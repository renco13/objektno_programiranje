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
};

Physics::Physics() : vx(0.0f), vy(0.0f), friction(0.0f) /*, gravity({0.0f, 9.8f})*/ {}

class Tank : public Physics{
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
    : x(initX), y(initY), terrain(terrain),
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

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tank");

    TerrainGenerator terrain;
    terrain.CreateMap();
    Tank tank(100.0f, 100.0f, terrain);

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Main game loop
    {
        // Update
        float fElapsedTime = GetFrameTime();
        float deltaTime = GetFrameTime();

        // User Done Updates
        terrain.OnUserUpdate(fElapsedTime);
        tank.Update(deltaTime);

        // Draw
        BeginDrawing();

        ClearBackground(SKYBLUE);

        terrain.DrawTerrain();
        tank.Draw(0.0f, 20.0f);     // X i Y = 20, ovo smo postavili malo vise jer je sprite padao malo ispod zemlje
                                    // kada testiramo sa krugom a da su X i Y = 0 onda krug dodaktne povrisnu normalno
        DrawFPS(10, 10);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
