#include "tank.h"
#include <vector>

Tank::Tank(float initX, float initY, TerrainGenerator& terrain)
    : x(initX), y(initY), terrain(terrain), physics(),
    tankTexture(LoadTexture("tankblue2.png")), bStable(true) {}

bool Tank::OnUserUpdate(float fElapsedTime)
{
    if (IsKeyDown(KEY_W)) {
        fShootingAngle -= 1.0f * fElapsedTime;
        if (fShootingAngle < -PI) {
            fShootingAngle += 2.0f * PI;
        }
    }

    if (IsKeyDown(KEY_S)) {
        fShootingAngle += 1.0f * fElapsedTime;
        if (fShootingAngle > PI) {
            fShootingAngle -= 2.0f * PI;
        }
    }

    float crosshairDistance = 50.0f; // Adjust this value based on your needs
    SetCrosshair(x + 20.0f + cosf(fShootingAngle) * crosshairDistance, y - 5.0f + sinf(fShootingAngle) * crosshairDistance);
    if (IsKeyDown(KEY_SPACE)) {
        chargingShot = true;
    }
    else {
        chargingShot = false;
        shotPower = 0.0f;
        fireWeapon = true;
    }

    // Dodajte poziv funkcije za ažuriranje snage pucanja
    UpdateShotPower(fElapsedTime);

    return true;
}

void Tank::Draw(float offsetX, float offsetY) {
    // Draw the tank at the correct position
    DrawTexture(tankTexture, static_cast<int>(x - offsetX), static_cast<int>(y - offsetY), WHITE);

    DrawCrosshair(crosshairX - offsetX, crosshairY - offsetY, 20);
    DrawChargingBar(50.0f);

    // Testni objekti
    //DrawCircle(static_cast<int>(x - offsetX), static_cast<int>(y - offsetY), 10, WHITE);
    //DrawRectangle(static_cast<int>(x - offsetX), static_cast<int>(y - offsetY), 10, 10, WHITE);
}

Tank::~Tank() {
    UnloadTexture(tankTexture);
}

void Tank::Update(float fElapsedTime) {
    // Do 10 physics iterations per frame - this allows smaller physics steps
    // giving rise to more accurate and controllable calculations
    for (int z = 0; z < 10; z++) {
        // Zadavanje gravitacije
        physics.ay += 2.0f;

        // Update velocity
        physics.vx += physics.ax * fElapsedTime;
        physics.vy += physics.ay * fElapsedTime;

        // Update position
        float fPotentialX = x + physics.vx * fElapsedTime;
        float fPotentialY = y + physics.vy * fElapsedTime;

        // Reset Acceleration;
        physics.ax = 0.0f;
        physics.ay = 0.0f;
        physics.bStable = false;

        // Collision check with the terrain
        float fAngle = atan2f(physics.vy, physics.vx);
        float fResponseX = 0;
        float fResponseY = 0;
        bool bCollision = false;

        // Kroz polovicu kruga objekta radius rotiramo prema smjeru kontakta sa terrainom
        for (float r = fAngle - PI / 2.0f; r < fAngle + PI / 2.0f; r += PI / 8.0f) {
            float fTestPosX = (physics.radius) * cosf(r) + fPotentialX;
            float fTestPosY = (physics.radius) * sinf(r) + fPotentialY;

            // Ogranicimo ih po velicin terraina
            if (fTestPosX >= nMapWidth)
                fTestPosX = nMapWidth - 1;
            if (fTestPosY >= nMapHeight)
                fTestPosY = nMapHeight - 1;
            if (fTestPosX < 0)
                fTestPosX = 0;
            if (fTestPosY < 0)
                fTestPosY = 0;

            // Test if any points on the semicrcle intersect with the terrain
            if (terrain.GetMap()[(int)fTestPosY * nMapWidth + (int)fTestPosX] != 0) {
                fResponseX += fPotentialX - fTestPosX;
                fResponseY += fPotentialY - fTestPosY;
                bCollision = true;
            }
        }

        // Calculate magnitueds of response and velocity vectors
        float fMagVelocity = sqrtf(physics.vx * physics.vx + physics.vy * physics.vy);
        float fMagResponse = sqrtf(fResponseX * fResponseX + fResponseY * fResponseY);

        if (bCollision) {
            // Forsira objekt da bude stabilan, zaustavlja objekt da pada kroz terrain
            physics.bStable = true;

            // Racuna refleksiju vektora od objektove vektora brzine
            float dot = physics.vx * (fResponseX / fMagResponse) + physics.vy * (fResponseY / fMagResponse);

            // Use friction coefficient to dampen the response (gubitak energije ili smanjivanje odskakanja)
            physics.vx = physics.friction * (-2.0f * dot * (fResponseX / fMagResponse) + physics.vx);
            physics.vy = physics.friction * (-2.0f * dot * (fResponseY / fMagResponse) + physics.vy);

            //Debry will die after a few bounces
            if (physics.nBounceBeforeDeath > 0) {
                physics.nBounceBeforeDeath--;
                physics.bDead = physics.nBounceBeforeDeath == 0;

                // Ako je objekt poginuo, odredit sto sljedece napravit
                //if (physics.bDead) {
                //    // Akcije nakon smrti objekta
                //    // = 0 nista, > 0 eksplozija
                //    int nResponse = physics.BounceDeathAction();
                //    if (nResponse > 0)
                //        Explosion(physics.px, physics.py, nResponse);
                //}
            }
        }

        else {
            // Ovo omugacava padanje dok se loopa
            // Zakomentiraj da tenk stoji u zraku
            x = fPotentialX;
            y = fPotentialY;
        }

        // Prekid micanja kad je mal pomak objekta
        if (fMagVelocity < 0.1f) physics.bStable = true;
    }
}

void Tank::SetCrosshair(float crosshairX, float crosshairY)
{
    this->crosshairX = crosshairX;
    this->crosshairY = crosshairY;
}

void Tank::DrawCrosshair(float offsetX, float offsetY, float size) {
    DrawLine(crosshairX - offsetX - 10, crosshairY - offsetY, crosshairX - offsetX + 10, crosshairY - offsetY, RED);
    DrawLine(crosshairX - offsetX, crosshairY - offsetY - 10, crosshairX - offsetX, crosshairY - offsetY + 10, RED);
}

void Tank::UpdateShotPower(float fElapsedTime) {
    if (chargingShot && shotPower < maxShotPower) {
        shotPower += fElapsedTime;
        // Ogranièite maksimalnu snagu pucanja
        if (shotPower > maxShotPower) {
            shotPower = maxShotPower;
        }
    }
}

void Tank::DrawChargingBar(float barWidth) {
    if (chargingShot) {
        DrawRectangle(static_cast<int>(x + 15.0f - barWidth / 2.0f), static_cast<int>(y - 15.0f + barOffsetY),
            static_cast<int>(barWidth * (shotPower / maxShotPower)), 5, RED);
    }
}