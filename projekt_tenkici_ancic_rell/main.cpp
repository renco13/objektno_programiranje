#include "raylib.h"
#include "terrain.h"
#include <vector>
#include <utility>
#include <list>

class Physics {
public:
    Physics();

    float px = 0.0f;    // Position
    float py = 0.0f;
    float vx = 0.0f;    // Velocity
    float vy = 0.0f;
    float ax = 0.0f;    // Acceleration
    float ay = 0.0f;

    float radius = 4.0f;    // Collision Check
    bool bStable = false;  // Has object stopped moving
    float friction;     // Smanjivanja impakta objekta od povrsinu zemlje

    void Draw(float fOffsetX, float fOffsetY);
    bool bDead = false;
    int nBounceBeforeDeath = 0;
};

//Physics::Physics() : vx(0.0f), vy(0.0f), friction(0.0f) {}
Physics::Physics() : 
    px(0.0f), py(0.0f), vx(0.0f), vy(0.0f), ax(0.0f), ay(0.0f),
    radius(4.0f), bStable(false), friction(0.0f), bDead(false), nBounceBeforeDeath(0) {}

// Debris class and everthing not working

//class Debris : public Physics {
//public:
//    Debris(float x, float y, TerrainGenerator& terrain);
//
//    void Update(float fElapsedTime);
//
//    void Draw(float offsetX, float offsetY);
//
//    virtual int BounceDeathAction() {
//        return 0;
//    }
//
//    virtual bool OnUserUpdate(float fElapsedTime);
//
//private:
//    int nMapWidth = 1200;
//    int nMapHeight = 800;
//    TerrainGenerator& terrain;
//    std::vector<Debris> debris;
//};
//
//Debris::Debris(float x, float y, TerrainGenerator& terrain) : Physics(), terrain(terrain) {
//    vx = 10.0f * cosf(((float)rand() / (float)RAND_MAX) * 2.0f * PI);
//    vy = 10.0f * sinf(((float)rand() / (float)RAND_MAX) * 2.0f * PI);
//    radius = 1.0f;
//    friction = 0.8f;
//    nBounceBeforeDeath = 3; 
//}
//
//void Debris::Update(float fElapsedTime) {// Update logic for debris
//    px += vx * fElapsedTime;
//    py += vy * fElapsedTime;
//
//    // Gravity
//    ay += 2.0f;
//
//    // Update velocity
//    vx += ax * fElapsedTime;
//    vy += ay * fElapsedTime;
//
//    // Reset Acceleration;
//    ax = 0.0f;
//    ay = 0.0f;
//    bStable = false;
//
//    // Collision check with the terrain
//    float fAngle = atan2f(vy, vx);
//    float fResponseX = 0;
//    float fResponseY = 0;
//    bool bCollision = false;
//
//    // Kroz polovicu kruga objekta radius rotiramo prema smjeru kontakta sa terrainom
//    for (float r = fAngle - PI / 2.0f; r < fAngle + PI / 2.0f; r += PI / 8.0f) {
//        float fTestPosX = (radius)*cosf(r) + px;
//        float fTestPosY = (radius)*sinf(r) + py;
//
//        // Ogranicimo ih po velicin terraina
//        if (fTestPosX >= nMapWidth)
//            fTestPosX = nMapWidth - 1;
//        if (fTestPosY >= nMapHeight)
//            fTestPosY = nMapHeight - 1;
//        if (fTestPosX < 0)
//            fTestPosX = 0;
//        if (fTestPosY < 0)
//            fTestPosY = 0;
//
//        // Test if any points on the semicircle intersect with the terrain
//        if (terrain.GetMap()[(int)fTestPosY * nMapWidth + (int)fTestPosX] != 0) {
//            fResponseX += px - fTestPosX;
//            fResponseY += py - fTestPosY;
//            bCollision = true;
//        }
//    }
//
//    // Calculate magnitudes of response and velocity vectors
//    float fMagVelocity = sqrtf(vx * vx + vy * vy);
//    float fMagResponse = sqrtf(fResponseX * fResponseX + fResponseY * fResponseY);
//
//    if (bCollision) {
//        // Forsira objekt da bude stabilan, zaustavlja objekt da pada kroz terrain
//        bStable = true;
//
//        // Racuna refleksiju vektora od objektove vektora brzine
//        float dot = vx * (fResponseX / fMagResponse) + vy * (fResponseY / fMagResponse);
//
//        // Use friction coefficient to dampen the response (gubitak energije ili smanjivanje odskakanja)
//        vx = friction * (-2.0f * dot * (fResponseX / fMagResponse) + vx);
//        vy = friction * (-2.0f * dot * (fResponseY / fMagResponse) + vy);
//
//        // Debris will die after a few bounces
//        if (nBounceBeforeDeath > 0) {
//            nBounceBeforeDeath--;
//            bDead = nBounceBeforeDeath == 0;
//
//            // Ako je objekt poginuo, odrediti što sljedeće napraviti
//            // if (bDead) {
//            //     // Akcije nakon smrti objekta
//            //     // = 0 ništa, > 0 eksplozija
//            //     int nResponse = BounceDeathAction();
//            //     if (nResponse > 0)
//            //         Explosion(px, py, nResponse);
//            // }
//        }
//    }
//    else {
//        // Ovo omogućava padanje dok se loopa
//        // Zakomentiraj da tenk stoji u zraku
//        px = px + vx * fElapsedTime;
//        py = py + vy * fElapsedTime;
//    }
//
//    // Prekid micanja kad je mal pomak objekta
//    if (fMagVelocity < 0.1f)
//        bStable = true;
//}
//
//void Debris::Draw(float fOffsetX, float fOffsetY) {
//    DrawRectangle(static_cast<int>(px - radius - fOffsetX), static_cast<int>(py - radius - fOffsetY),
//        static_cast<int>(2 * radius), static_cast<int>(2 * radius), GREEN);
//}
//
//bool Debris::OnUserUpdate(float fElapsedTime) {
//    if (IsKeyPressed(MOUSE_BUTTON_LEFT)) {
//        Vector2 mousePosition = GetMousePosition();
//        debris.push_back(Debris(mousePosition.x + fCameraPosX, mousePosition.y + fCameraPosY, terrain));
//    }
//
//    return true;
//}

class Tank : public Physics {
public:
    Tank(float initX, float initY, TerrainGenerator& terrain);
    ~Tank();
    void Draw(float offsetX, float offsetY);
    void Update(float fElapsedTime);

private:
    int nMapWidth = 1200;
    int nMapHeight = 600;
    float x, y;
    Physics physics;
    float radius = 4.0f;
    bool bStable;
    Texture2D tankTexture;
    TerrainGenerator& terrain;
    //int nBounceBeforeDeath;
    //bool bDead;
};

Tank::Tank(float initX, float initY, TerrainGenerator& terrain)
    : x(initX), y(initY), terrain(terrain), physics(),
    tankTexture(LoadTexture("tankblue2.png")), bStable(true) {}

void Tank::Draw(float offsetX, float offsetY) {
    // Draw the tank at the correct position
    DrawTexture(tankTexture, static_cast<int>(x - offsetX), static_cast<int>(y - offsetY), WHITE);

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

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tank");

    TerrainGenerator terrain;
    terrain.CreateMap();
    Tank tank(100.0f, 100.0f, terrain);

    //std::vector<Debris> debris;
    //debris.push_back(Debris(100.0f, 100.0f, terrain));

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Main game loop
    {
        // Update
        float fElapsedTime = GetFrameTime();
        float deltaTime = GetFrameTime();

        // User Done Updates
        terrain.OnUserUpdate(fElapsedTime);
        tank.Update(deltaTime);
        //debris.Update(fElapsedTime);

        // Draw
        BeginDrawing();

        ClearBackground(SKYBLUE);

        terrain.DrawTerrain();
        tank.Draw(0.0f, 20.0f);     // X i Y = 20, ovo smo postavili malo vise jer je sprite padao malo ispod zemlje
                                    // kada testiramo sa krugom a da su X i Y = 0 onda krug dodaktne povrisnu normalno
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePosition = GetMousePosition();
            // Convert mouse coordinates to world coordinates based on your camera or game logic
            float worldMouseX = mousePosition.x + terrain.GetCameraPosX();
            float worldMouseY = mousePosition.y + terrain.GetCameraPosY();
            // Trigger an explosion at the mouse position
            Explosion(terrain.GetMapWidth(), terrain.GetMapHeight(), terrain.GetMap(), worldMouseX, worldMouseY, 10.0f);
        }

        //for (auto& d : debris) {
        //    d.Update(fElapsedTime);
        //    d.Draw(0.0f, 0.0f);
        //}
        //debris.Draw(0.0f, 0.0f);
       
        DrawFPS(10, 10);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
