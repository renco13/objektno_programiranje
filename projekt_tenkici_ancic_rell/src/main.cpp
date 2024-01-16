#include "raylib.h"
#include "physics.h"
#include "terrain.h"
#include "tank.h"
#include "debris.h"
#include <vector>
#include <utility>
#include <list>

// EXPLOSION BOOM

void Explosion(int nMapWidth, int nMapHeight, unsigned char* map, float fWorldX, float fWorldY, float fRadius) {
    auto CircleBresenham = [&](int xc, int yc, int r) {
        // Ovo je sve sa wikipedia
        int x = 0;
        int y = r;
        int p = 3 - 2 * r;
        if (!r) {
            return;
        }
        auto drawline = [&](int sx, int ex, int ny) {
            for (int i = sx; i < ex; i++) {
                if (ny >= 0 && ny < nMapHeight && i >= 0 && i < nMapWidth) {
                    map[ny * nMapWidth + i] = 0;
                }
            }
            };
        while (y >= x) {
            // Crtanje linija za rupu
            drawline(xc - x, xc + x, yc - y);
            drawline(xc - y, xc + y, yc - x);
            drawline(xc - x, xc + x, yc + y);
            drawline(xc - y, xc + y, yc + x);
            if (p < 0) p += 4 * x++ + 6;
            else p += 4 * (x++ - y--) + 10;
        }
        };

    // Birsanje terraina za formiranje cartera
    CircleBresenham(fWorldX, fWorldY, fRadius);
}

// Missile class

//class Missile : public Physics {
//public:    
//    Missile() : Physics();
//    Missile(float initX, float initY, float _vx, float _vy) : Physics(), terrain(terrain) {
//        radius = 2.5f;
//        friction = 0.5f;
//        vx = _vx;
//        vy = _vy;
//        bDead = false;
//        nBounceBeforeDeath = 1;
//    }
//
//    bool bDropped = false;
//
//    void Draw(float fOffsetX, float fOffsetY) {
//        DrawCircle(px - fOffsetX, py - fOffsetY, radius, YELLOW);
//    }
//
//    void Update(float fElapsedTime);
//
//    virtual int BounceDeathAction() {
//        return 20; // Explode Big
//    }
//
//    virtual bool OnUserUpdate(float fElapsedTime);
//
//private:
//    int nMapWidth = 800;
//    int nMapHeight = 600;
//    float x, y;
//    Physics physics;
//    float radius = 4.0f;
//    bool bStable;
//    TerrainGenerator& terrain;
//};
//
//void Missile::Update(float fElapsedTime) {
//    // Do 10 physics iterations per frame - this allows smaller physics steps
//    // giving rise to more accurate and controllable calculations
//    for (int z = 0; z < 10; z++) {
//        // Zadavanje gravitacije
//        physics.ay += 2.0f;
//
//        // Update velocity
//        physics.vx += physics.ax * fElapsedTime;
//        physics.vy += physics.ay * fElapsedTime;
//
//        // Update position
//        float fPotentialX = x + physics.vx * fElapsedTime;
//        float fPotentialY = y + physics.vy * fElapsedTime;
//
//        // Reset Acceleration;
//        physics.ax = 0.0f;
//        physics.ay = 0.0f;
//        physics.bStable = false;
//
//        // Collision check with the terrain
//        float fAngle = atan2f(physics.vy, physics.vx);
//        float fResponseX = 0;
//        float fResponseY = 0;
//        bool bCollision = false;
//
//        // Kroz polovicu kruga objekta radius rotiramo prema smjeru kontakta sa terrainom
//        for(float r = fAngle - PI / 2.0f; r < fAngle + PI / 2.0f; r += PI / 8.0f) {
//            float fTestPosX = (physics.radius) * cosf(r) + fPotentialX;
//            float fTestPosY = (physics.radius) * sinf(r) + fPotentialY;
//
//            // Ogranicimo ih po velicin terraina
//            if (fTestPosX >= nMapWidth)
//                fTestPosX = nMapWidth - 1;
//            if (fTestPosY >= nMapHeight)
//                fTestPosY = nMapHeight - 1;
//            if (fTestPosX < 0)
//                fTestPosX = 0;
//            if (fTestPosY < 0)
//                fTestPosY = 0;
//
//            // Test if any points on the semicrcle intersect with the terrain
//            if (terrain.GetMap()[(int)fTestPosY * nMapWidth + (int)fTestPosX] != 0) {
//                fResponseX += fPotentialX - fTestPosX;
//                fResponseY += fPotentialY - fTestPosY;
//                bCollision = true;
//            }
//        }
//
//        // Calculate magnitueds of response and velocity vectors
//        float fMagVelocity = sqrtf(physics.vx * physics.vx + physics.vy * physics.vy);
//        float fMagResponse = sqrtf(fResponseX * fResponseX + fResponseY * fResponseY);
//
//        if (bCollision) {
//            // Forsira objekt da bude stabilan, zaustavlja objekt da pada kroz terrain
//            physics.bStable = true;
//
//            // Racuna refleksiju vektora od objektove vektora brzine
//            float dot = physics.vx * (fResponseX / fMagResponse) + physics.vy * (fResponseY / fMagResponse);
//
//            // Use friction coefficient to dampen the response (gubitak energije ili smanjivanje odskakanja)
//            physics.vx = physics.friction * (-2.0f * dot * (fResponseX / fMagResponse) + physics.vx);
//            physics.vy = physics.friction * (-2.0f * dot * (fResponseY / fMagResponse) + physics.vy);
//
//            //Debry will die after a few bounces
//            if (physics.nBounceBeforeDeath > 0) {
//                physics.nBounceBeforeDeath--;
//                physics.bDead = physics.nBounceBeforeDeath == 0;
//
//                // Ako je objekt poginuo, odredit sto sljedece napravit
//                //if (physics.bDead) {
//                //    // Akcije nakon smrti objekta
//                //    // = 0 nista, > 0 eksplozija
//                //    int nResponse = physics.BounceDeathAction();
//                //    if (nResponse > 0)
//                //        Explosion(physics.px, physics.py, nResponse);
//                //}
//            }
//        }
//
//        else {
//            // Ovo omugacava padanje dok se loopa
//            // Zakomentiraj da tenk stoji u zraku
//            x = fPotentialX;
//            y = fPotentialY;
//        }
//
//        // Prekid micanja kad je mal pomak objekta
//        if (fMagVelocity < 0.1f) physics.bStable = true;
//    }
//}
//
//bool Missile::OnUserUpdate(float fElpasedTime) {
//    if (IsKeyPressed(MOUSE_BUTTON_RIGHT)) {
//        Draw(0.0f, 0.0f);
//    }
//
//    return true;
//}

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tank");

    TerrainGenerator terrain;
    terrain.CreateMap();
    Tank tank(100.0f, 100.0f, terrain);
    //Missile missile;

    std::vector<Debris> debris;
    debris.push_back(Debris(screenWidth, screenHeight, 100.0f, 100.0f, terrain));

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Main game loop
    {
        // Update
        float fElapsedTime = GetFrameTime();

        // User Done Updates
        terrain.OnUserUpdate(fElapsedTime);
        tank.OnUserUpdate(fElapsedTime);
        tank.Update(fElapsedTime);
        // Missile stuff
        
        //if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        //    // Adjust the values based on your requirements
        //    float missileStartX = tank.GetX();
        //    float missileStartY = tank.GetY();
        //    float missileSpeed = 100.0f; // Adjust as needed
        //
        //    // Calculate missile initial velocity based on tank's shooting angle
        //    float missileVX = cosf(tank.GetShootingAngle()) * missileSpeed;
        //    float missileVY = sinf(tank.GetShootingAngle()) * missileSpeed;
        //
        //    // Fire the missile
        //    missile.Drop(missileStartX, missileStartY, missileVX, missileVY);
        //}
        //
        //missile.Update(fElapsedTime);

        // Draw
        BeginDrawing();

        ClearBackground(SKYBLUE);

        terrain.DrawTerrain();
        tank.Draw(0.0f, 20.0f);     // X i Y = 20, ovo smo postavili malo vise jer je sprite padao malo ispod zemlje
                                    // kada testiramo sa krugom a da su X i Y = 0 onda krug dodaktne povrisnu normalno
        
        //missile.Draw(0.0f, 20.0f);

        // Unistavanje zemlje sa livim klikom
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePosition = GetMousePosition();
            // Convert mouse coordinates to world coordinates based on your camera or game logic
            float worldMouseX = mousePosition.x + terrain.GetCameraPosX();
            float worldMouseY = mousePosition.y + terrain.GetCameraPosY();
            // Trigger an explosion at the mouse position
            Explosion(terrain.GetMapWidth(), terrain.GetMapHeight(), terrain.GetMap(), worldMouseX, worldMouseY, 40.0f);
            debris.push_back(Debris(terrain.GetMapWidth(), terrain.GetMapHeight(), worldMouseX, worldMouseY, terrain));
        }

        for (auto& d : debris) {
            d.Update(fElapsedTime);
            d.Draw(0.0f, 0.0f);
        }

        // Crosshair i shot charging bar
        tank.DrawCrosshair(0.0f, 0.0f, 20);
        tank.DrawChargingBar(50.0f);    // Postavi sirinu trake prema potrebi
       
        DrawFPS(10, 10);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
