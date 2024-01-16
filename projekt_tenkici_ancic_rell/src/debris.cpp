#include "debris.h"

Debris::Debris(int nMapWidth, int nMapHeight, float x, float y, TerrainGenerator& terrain) : Physics(), terrain(terrain) {
    vx = 10.0f * cosf(((float)rand() / (float)RAND_MAX) * 2.0f * PI);
    vy = 10.0f * sinf(((float)rand() / (float)RAND_MAX) * 2.0f * PI);
    radius = 1.0f;
    friction = 0.8f;
    nBounceBeforeDeath = 3;
}

void Debris::Update(float fElapsedTime) {// Update logic for debris
    for (int z = 0; z < 10; z++) {
        px += vx * fElapsedTime;
        py += vy * fElapsedTime;

        // Gravity
        ay += 2.0f;

        // Update velocity
        vx += ax * fElapsedTime;
        vy += ay * fElapsedTime;

        // Reset Acceleration;
        ax = 0.0f;
        ay = 0.0f;
        bStable = false;

        // Collision check with the terrain
        float fAngle = atan2f(vy, vx);
        float fResponseX = 0;
        float fResponseY = 0;
        bool bCollision = false;

        // Kroz polovicu kruga objekta radius rotiramo prema smjeru kontakta sa terrainom
        for (float r = fAngle - PI / 2.0f; r < fAngle + PI / 2.0f; r += PI / 8.0f) {
            float fTestPosX = (radius)*cosf(r) + px;
            float fTestPosY = (radius)*sinf(r) + py;

            // Ogranicimo ih po velicin terraina
            if (fTestPosX >= nMapWidth)
                fTestPosX = nMapWidth - 1;
            if (fTestPosY >= nMapHeight)
                fTestPosY = nMapHeight - 1;
            if (fTestPosX < 0)
                fTestPosX = 0;
            if (fTestPosY < 0)
                fTestPosY = 0;

            // Test if any points on the semicircle intersect with the terrain
            if (terrain.GetMap()[(int)fTestPosY * nMapWidth + (int)fTestPosX] != 0) {
                fResponseX += px - fTestPosX;
                fResponseY += py - fTestPosY;
                bCollision = true;
            }
        }

        // Calculate magnitudes of response and velocity vectors
        float fMagVelocity = sqrtf(vx * vx + vy * vy);
        float fMagResponse = sqrtf(fResponseX * fResponseX + fResponseY * fResponseY);

        if (bCollision) {
            // Forsira objekt da bude stabilan, zaustavlja objekt da pada kroz terrain
            bStable = true;

            // Racuna refleksiju vektora od objektove vektora brzine
            float dot = vx * (fResponseX / fMagResponse) + vy * (fResponseY / fMagResponse);

            // Use friction coefficient to dampen the response (gubitak energije ili smanjivanje odskakanja)
            vx = friction * (-2.0f * dot * (fResponseX / fMagResponse) + vx);
            vy = friction * (-2.0f * dot * (fResponseY / fMagResponse) + vy);

            // Debris will die after a few bounces
            if (nBounceBeforeDeath > 0) {
                nBounceBeforeDeath--;
                bDead = nBounceBeforeDeath == 0;

                //Ako je objekt poginuo, odrediti što sljedeæe napraviti
                if (bDead) {
                    // Akcije nakon smrti objekta
                    // = 0 ništa, > 0 eksplozija
                    int nResponse = BounceDeathAction();
                    //if (nResponse > 0) {
                    //    Explosion explosion(terrain);
                    //    explosion.TriggerExplosion(nMapWidth, nMapHeight, terrain.GetMap(), px, py, nResponse);
                    //}
                }
            }
        }
        else {
            // Ovo omoguæava padanje dok se loopa
            // Zakomentiraj da tenk stoji u zraku
            px = px + vx * fElapsedTime;
            py = py + vy * fElapsedTime;
        }

        // Prekid micanja kad je mal pomak objekta
        if (fMagVelocity < 0.1f)
            bStable = true;
    }
}

void Debris::Draw(float fOffsetX, float fOffsetY) {
    DrawRectangle(static_cast<int>(px - radius - fOffsetX), static_cast<int>(py - radius - fOffsetY),
        static_cast<int>(2 * radius), static_cast<int>(2 * radius), DARKGREEN);
}

bool Debris::OnUserUpdate(float fElapsedTime) {
    if (IsKeyPressed(MOUSE_BUTTON_RIGHT)) {
        Vector2 mousePosition = GetMousePosition();
        debris.push_back(Debris(terrain.GetMapWidth(), terrain.GetMapHeight(), mousePosition.x + terrain.GetCameraPosX(), mousePosition.y + terrain.GetCameraPosY(), terrain));
    }

    return true;
}

// EXPLOSION BOOM
