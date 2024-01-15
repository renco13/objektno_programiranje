#include "raylib.h"
#include "terrain.h"
#include <vector>
#include <utility>
#include <list>

// terrain class original

//class TerrainGenerator {
//public:
//    TerrainGenerator() {
//        map = new unsigned char[nMapWidth * nMapHeight];
//    }
//
//    ~TerrainGenerator() {
//        delete[] map;
//    }
//
//    virtual bool OnUserUpdate(float fElapsedTime) {
//        // Generating new random map with M
//        if (IsKeyReleased(KEY_M))
//            CreateMap();
//
//        // Scrolling after mouse hits edge of screen
//        float fMapScrollSpeed = 400.0f;
//        // Povecan area registracije da je mis na rubu ekrana
//        float fScrollArea = 50.0f;
//        // Smoothing
//        float fSpeedX = 0.0f;
//        float fSpeedY = 0.0f;
//        // X
//        if (GetMouseX() < fScrollArea) {
//            fSpeedX = (fScrollArea - GetMouseX()) / fScrollArea * fMapScrollSpeed;
//            fCameraPosX -= fSpeedX * fElapsedTime;
//        }
//        if (GetMouseX() > ScreenWidth - fScrollArea) {
//            fSpeedX = (GetMouseX() - (ScreenWidth - fScrollArea)) / fScrollArea * fMapScrollSpeed;
//            fCameraPosX += fSpeedX * fElapsedTime;
//        }
//        // Y
//        if (GetMouseY() < fScrollArea) {
//            fSpeedY = (fScrollArea - GetMouseY()) / fScrollArea * fMapScrollSpeed;
//            fCameraPosY -= fSpeedY * fElapsedTime;
//        }
//        if (GetMouseY() > ScreenHeight - fScrollArea) {
//            fSpeedY = (GetMouseY() - (ScreenHeight - fScrollArea)) / fScrollArea * fMapScrollSpeed;
//            fCameraPosY += fSpeedY * fElapsedTime;
//        }
//
//        // Clamp map boundaries
//        if (fCameraPosX < 0) fCameraPosX = 0;
//        if (fCameraPosX >= nMapWidth - ScreenWidth) fCameraPosX = nMapWidth - ScreenWidth;
//        if (fCameraPosY < 0) fCameraPosY = 0;
//        if (fCameraPosY >= nMapHeight - ScreenHeight) fCameraPosY = nMapHeight - ScreenHeight;
//
//        return true;
//    }
//
//    void CreateMap() {
//        // Used 1D Perlin Noise
//        float* fSurface = new float[nMapWidth];
//        float* fNoiseSeed = new float[nMapWidth];
//
//        // Populate with noise
//        for (int i = 0; i < nMapWidth; i++)
//            fNoiseSeed[i] = (float)rand() / (float)RAND_MAX;
//
//        // Clamp noise to half way up screen
//        fNoiseSeed[0] = 0.5f;
//
//        // Generate 1D map
//        PerlinNoise1D(nMapWidth, fNoiseSeed, 8, 2.0f, fSurface);
//
//        // Fill 2D map based on adjacent 1D map
//        for (int x = 0; x < nMapWidth; x++)
//            for (int y = 0; y < nMapHeight; y++) {
//                if (y >= fSurface[x] * nMapHeight)
//                    map[y * nMapWidth + x] = 1;
//                else
//                    map[y * nMapWidth + x] = 0;
//            }
//
//        // Clean up!
//        delete[] fSurface;
//        delete[] fNoiseSeed;
//    }
//
//    // Taken from Perlin Noise Video https://youtu.be/6-0UaeJBumA
//    void PerlinNoise1D(int nCount, float* fSeed, int nOctaves, float fBias, float* fOutput) {
//        // Used 1D Perlin Noise
//        for (int x = 0; x < nCount; x++) {
//            float fNoise = 0.0f;
//            float fScaleAcc = 0.0f;
//            float fScale = 1.0f;
//
//            for (int o = 0; o < nOctaves; o++) {
//                int nPitch = nCount >> o;
//                int nSample1 = (x / nPitch) * nPitch;
//                int nSample2 = (nSample1 + nPitch) % nCount;
//                float fBlend = (float)(x - nSample1) / (float)nPitch;
//                float fSample = (1.0f - fBlend) * fSeed[nSample1] + fBlend * fSeed[nSample2];
//                fScaleAcc += fScale;
//                fNoise += fSample * fScale;
//                fScale = fScale / fBias;
//            }
//
//            // Scale to seed range
//            fOutput[x] = fNoise / fScaleAcc;
//        }
//    }
//
//    void DrawTerrain() {
//        for (int x = 0; x < nMapWidth; x++) {
//            for (int y = 0; y < nMapHeight; y++) {
//
//                // Porjvera je li unutar bounds STARO NE TREBA AKO JE nMapHeight 600
//                //int mapX = static_cast<int>(fCameraPosX) + x;
//                //int mapY = static_cast<int>(fCameraPosY) + y;
//
//                // Provjera je li unutar bounds
//                //if (mapX >= 0 && mapX < nMapWidth && mapY >= 0 && mapY < nMapHeight) {
//                //    if (map[(y + (int)fCameraPosY) * nMapWidth + (x + (int)fCameraPosX)]) {
//                //        // Draw terrain block at (x, y)
//                //        DrawRectangle(x, y, 1, 1, DARKGREEN);
//                //    }
//                //}
//
//                if (map[(y + (int)fCameraPosY) * nMapWidth + (x + (int)fCameraPosX)] == 1) {
//                    // Draw terrain block at (x, y)
//                    DrawRectangle(x, y, 1, 1, DARKGREEN);
//                }
//            }
//        }
//    }
//
//private:
//    // Velicina prozora
//    const int ScreenWidth = 800;
//    const int ScreenHeight = 600;
//
//    // Velicina terraina
//    int nMapWidth = 1600;
//    int nMapHeight = 600;
//    unsigned char* map = nullptr;
//
//    // Default pozicije kamera
//    float fCameraPosX = 0.0f;
//    float fCameraPosY = 0.0f;
//};

// physics class OLD

//class cDummy;
//
//class cPhysicsObject {
//public:
//    // Position
//    float px = 0.0f;
//    float py = 0.0f;
//    // Velocity
//    float vx = 0.0f;
//    float vy = 0.0f;
//    // Acceleration
//    float ax = 0.0f;
//    float ay = 0.0f;
//
//    float radius = 4.0f;            // Circle collision
//    bool bStable = false;           // Je li se objekt stao micati
//    float fFriction = 0.8f;     
//
//    int nBounceBeforeDeath = -1;    // Broj bounceova do smrti 
//    bool bDead = false;             // Indikator da je objekt mrtav i da se brise
//
//    cPhysicsObject(float x = 0.0f, float y = 0.0f) {
//        px = x;
//        py = y;
//    }
//
//    virtual void Draw(float fOffsetX, float fOffsetY) {
//
//    }
//
//    virtual int BounceDeathAction() = 0;
//
//    virtual bool OnUserUpdate() {
//        if (IsKeyPressed(MOUSE_BUTTON_MIDDLE)) {
//            // Now cDummy is recognized by the compiler
//            cDummy* p = new cDummy(GetMouseX() + fCameraPosX, GetMouseY() + fCameraPosY);
//            listObjects.push_back(p);
//        }
//
//        for (auto& p : listObjects) {
//            p->Draw(fCameraPosX, fCameraPosY);
//        }
//        return true;
//    }
//
//    
//
//private:
//    // Lista za stvari
//    std::list<cPhysicsObject*> listObjects;
//
//    // Default pozicije kamera
//    float fCameraPosX = 0.0f;
//    float fCameraPosY = 0.0f;
//};
//
//std::vector<std::pair<float, float>> DefineDummy()
//{
//    // Defines a circle with a line fom center to edge
//    std::vector<std::pair<float, float>> vecModel;
//    vecModel.push_back({ 0.0f, 0.0f });
//    for (int i = 0; i < 10; i++)
//        vecModel.push_back({ cosf(i / 9.0f * 2.0f * 3.14159f) , sinf(i / 9.0f * 2.0f * 3.14159f) });
//    return vecModel;
//}
//
//class cDummy : public cPhysicsObject {
//public:
//    cDummy(float x = 0.0f, float y = 0.0f) : cPhysicsObject(x, y) {}
//
//    virtual void Draw(float fOffsetX, float fOffsetY) {
//        DrawCircle(static_cast<int>(px - fOffsetX), static_cast<int>(py - fOffsetY), static_cast<int>(radius), YELLOW);
//    }
//
//    virtual int BounceDeathAction() override{
//        return 0;
//    }
//
//private:
//    static std::vector<std::pair<float, float>> vecModel;
//};
//
//std::vector<std::pair<float, float>> cDummy::vecModel = DefineDummy();

// Physics Object class
//
//class PhysicsObject {
//public:
//    PhysicsObject(float x = 0.0f, float y = 0.0f);
//    virtual ~PhysicsObject();
//
//    // Position
//    float px = 0.0f;
//    float py = 0.0f;
//    // Velocity
//    float vx = 0.0f;
//    float vy = 0.0f;
//    // Acceleration
//    float ax = 0.0f;
//    float ay = 0.0f;
//
//    float radius = 4.0f;            // Circle collision
//    bool bStable = false;           // Je li se objekt stao micati
//    float fFriction = 0.8f;     
//
//    int nBounceBeforeDeath = -1;    // Broj bounceova do smrti 
//    bool bDead = false;             // Indikator da je objekt mrtav i da se brise
//
//    virtual void Draw(float fOffsetX, float fOffsetY) = 0;
//    virtual int BounceDeathAction() = 0;
//
//    //virtual bool OnUserUpdate() {
//    //    if (IsKeyPressed(MOUSE_BUTTON_MIDDLE)) {
//    //        // Now cDummy is recognized by the compiler
//    //        cDummy* p = new cDummy(GetMouseX() + fCameraPosX, GetMouseY() + fCameraPosY);
//    //        listObjects.push_back(p);
//    //    }
//    //    for (auto& p : listObjects) {
//    //        p->Draw(fCameraPosX, fCameraPosY);
//    //    }
//    //    return true;
//    //}
//
//private:
//    //// Lista za stvari
//    //std::list<PhysicsObject*> listObjects;
//    //// Default pozicije kamera
//    //float fCameraPosX = 0.0f;
//    //float fCameraPosY = 0.0f;
//};
//
//PhysicsObject::PhysicsObject(float x, float y) {
//    px = x;
//    py = y;
//}
//
//PhysicsObject::~PhysicsObject() {}
//
//// Tank Class
//
//class Tank : public PhysicsObject {
//public:
//    Tank(float x, float y);
//    virtual void Draw(float fOffsetX, float fOffsetY);
//    float fShootAngle = 0.0f;
//    void setTeam(int nT);
//    int team() const;
//};
//
//Tank::Tank(float x, float y) : PhysicsObject(x, y) {
//    radius = 3.3f;
//    fFriction = 0.2f;
//    bDead = false;
//}
//
//void Tank::Draw(float fOffsetX, float fOffsetY) {
//    DrawRectangle(static_cast<int>(px - fOffsetX), static_cast<int>(py - fOffsetY), static_cast<int>(radius * 2), static_cast<int>(radius * 2), BLUE);
//}

class Physics {
public:
    Physics();

    float radius = 4.0f; // Collision Check

    void Update(float deltaTime);

    void SetVelocityX(float vx);
    void SetVelocityY(float vy);

    float GetFriction();

    float GetVelocityX();
    float GetVelocityY();

private:
    float vx;
    float vy;
    float friction;
};

Physics::Physics() : vx(0.0f), vy(0.0f), friction(0.0f) {}

void Physics::Update(float deltaTime) {
    vy += friction * deltaTime;
}

float Physics::GetVelocityX() {
    return vx;
}

float Physics::GetVelocityY() {
    return vy;
}

void Physics::SetVelocityX(float newVx) {
    vx = newVx;
}

void Physics::SetVelocityY(float newVy) {
    vy = newVy;
}

float Physics::GetFriction() {
    return friction;
}

class Tank {
public:
    Tank(float initX, float initY, TerrainGenerator& terrain);

    void Update(float deltaTime);

    void Draw(float offsetX, float offsetY);



private:
    int nMapWidth = 1600;
    int nMapHeight = 600;
    float x, y;
    Physics physics;
    float radius = 4.0f;
    bool bStable;
    TerrainGenerator& terrain;
    //int nBounceBeforeDeath;
    //bool bDead;
};

Tank::Tank(float initX, float initY, TerrainGenerator& terrain) : x(initX), y(initY), terrain(terrain), bStable(true) {}

void Tank::Update(float deltaTime) {
    physics.Update(deltaTime);

    // Update tank's position based on physics
    float fPotentialX = x + physics.GetVelocityX() * deltaTime;
    float fPotentialY = y + physics.GetVelocityY() * deltaTime;

    // Collision Check With Map
    float fAngle = atan2f(physics.GetVelocityY(), physics.GetVelocityX());
    float fResponseX = 0;
    float fResponseY = 0;
    bool bCollision = false;

    // Iterate through semicircle of objects radius rotated to direction of travel
    for (float r = fAngle - 3.14159f / 2.0f; r < fAngle + 3.14159f / 2.0f; r += 3.14159f / 8.0f) {
        // Calculate test point on circumference of circle
        float fTestPosX = (radius)*cosf(r) + fPotentialX;
        float fTestPosY = (radius)*sinf(r) + fPotentialY;

        // Constrain to test within map boundary
        if (fTestPosX >= nMapWidth) fTestPosX = nMapWidth - 1;
        if (fTestPosY >= nMapHeight) fTestPosY = nMapHeight - 1;
        if (fTestPosX < 0) fTestPosX = 0;
        if (fTestPosY < 0) fTestPosY = 0;

        // Test if any points on semicircle intersect with terrain
        if (terrain.GetMap()[(int)fTestPosY * nMapWidth + (int)fTestPosX] != 0) {
            // Accumulate collision points to give an escape response vector
            // Effectively, normal to the areas of contact
            fResponseX += fPotentialX - fTestPosX;
            fResponseY += fPotentialY - fTestPosY;
            bCollision = true;
        }
    }

    // Calculate magnitudes of response and velocity vectors
    float fMagVelocity = sqrtf(physics.GetVelocityX() * physics.GetVelocityX() + physics.GetVelocityY() * physics.GetVelocityY());
    float fMagResponse = sqrtf(fResponseX * fResponseX + fResponseY * fResponseY);

    // Collision occurred
    if (bCollision) {
        // Force object to be stable, this stops the object penetrating the terrain
        bStable = true;

        // Calculate reflection vector of objects velocity vector, using response vector as normal
        float dot = physics.GetVelocityX() * (fResponseX / fMagResponse) + physics.GetVelocityY() * (fResponseY / fMagResponse);

        // Use friction coefficient to dampen response (approximating energy loss)
        physics.SetVelocityX(physics.GetFriction() * (-2.0f * dot * (fResponseX / fMagResponse) + physics.GetVelocityX()));
        physics.SetVelocityY(physics.GetFriction() * (-2.0f * dot * (fResponseY / fMagResponse) + physics.GetVelocityY()));

        // Some objects will "die" after several bounces
        //if (nBounceBeforeDeath > 0) {
        //    nBounceBeforeDeath--;
        //    bDead = nBounceBeforeDeath == 0;

        //    // If object died, work out what to do next
        //    if (bDead) {
        //        // Action upon object death
        //        // = 0 Nothing
        //        // > 0 Explosion
        //        int nResponse = Boom();
        //        if (nResponse > 0)
        //            Boom(x, y, nResponse);
        //    }
        //}
    }
    else {
        // No collision so update objects position
        x = fPotentialX;
        y = fPotentialY;
    }

    y += physics.GetVelocityY() * deltaTime;
}

void Tank::Draw(float offsetX, float offsetY) {
    // Retrieve terrain height at tank's x position
    //int terrainX = static_cast<int>(fCameraPosX + x);
    //if (terrainX >= 0 && terrainX < nMapWidth && fSurface != nullptr) {
    //    float terrainHeight = fSurface[terrainX] * nMapHeight;
    //    y = terrainHeight;
    //}

    // Draw the tank at the correct position
    DrawRectangle(static_cast<int>(x - offsetX), static_cast<int>(y - offsetY), 20, 20, RED);
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
    //Tank tank(float fOffsetX, float fOffsetY);
    //cDummy physicsDummy;

    SetTargetFPS(60);

    while (!WindowShouldClose()) // Main game loop
    {
        // Update
        float fElapsedTime = GetFrameTime();
        float deltaTime = GetFrameTime();

        // User Done Updates
        
        terrain.OnUserUpdate(fElapsedTime);
        tank.Update(deltaTime);
        //physicsDummy.OnUserUpdate();

        // Old random map regeneration
        //if (IsKeyReleased(KEY_M))
        //    terrain.CreateMap();

        // Draw
        BeginDrawing();

        ClearBackground(SKYBLUE);

        terrain.DrawTerrain();
        tank.Draw(0.0f, 0.0f);

        DrawFPS(10, 10);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
