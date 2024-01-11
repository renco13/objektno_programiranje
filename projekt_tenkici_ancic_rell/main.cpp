#include <iostream>
#include "raylib.h"
#include "tank.h"
#include "projectile.h"
#include "turntimer.h"
#include "cmath"

//void GameMenu(); //trigger za glavni meni
//void GameSettings(); //trigger za postavke
//void GameQuit(); //trigger za izlazak iz igre
//void GameStart(); //trigger za graficko pokretanje igre
//void GameUpdatePlayFrame(); //trigger za update grafickog crtnja igre ili pokrecanja igra 

const int screenWidth = 1280;
const int screenHeight = 720;

class Terrain {
public:
    Terrain() {
        map = nullptr;
    }

    ~Terrain() {
        if (map != nullptr) {
            delete[] map;
            map = nullptr;
        }
    }

    virtual bool OnUserUpdate(float fElaspedTime) {
        //ponovno generiranje zemlje
        if (IsKeyPressed(KEY_M))
            terrainCreate();

        //crtanje neba
        for (int x = 0; x < screenWidth; x++) {
            for (int y = 0; y < screenHeight; y++) {
                switch (map[(y)*terrainWidth + (x)]) {
                case 0:
                    DrawPixel(x, y, SKYBLUE);
                    break;
                case 1:
                    DrawPixel(x, y, DARKGREEN);
                    break;
                }
            }
        }

        return true;
    }
    //void UpdateTerrain(float fElapsedTime) {
    //    OnUserUpdate(fElapsedTime);
    //}
private:
    int terrainWidth = 1280;
    int terrainHeight = 720;
    unsigned char* map = nullptr;

    virtual bool OnUserCreate() {
        if (map != nullptr) {
            delete[] map;
            map = nullptr;
        }

        map = new unsigned char[terrainWidth * terrainHeight];
        memset(map, 0, terrainWidth * terrainHeight * sizeof(unsigned char));
        terrainCreate();

        return true;
    }

    //virtual bool OnUserUpdate(float fElaspedTime) {
    //    //ponovno generiranje zemlje
    //    if (IsKeyPressed(KEY_M))
    //        terrainCreate();
    //    
    //    //crtanje neba
    //    for (int x = 0; x < screenWidth; x++) {
    //        for (int y = 0; y < screenHeight; y++) {
    //            switch (map[(y)*terrainWidth + (x)]) {
    //            case 0:
    //                DrawPixel(x, y, SKYBLUE);
    //                break;
    //            case 1:
    //                DrawPixel(x, y, DARKGREEN);
    //                break;
    //            }
    //        }
    //    }

    //    return true;
    //}

    void terrainCreate() {
        float* fSurface = new float[terrainWidth];
        float* fNoiseSeed = new float[terrainWidth];

        for (int i = 0; i < terrainWidth; i++) {
            fNoiseSeed[i] = (float)rand() / (float)RAND_MAX;
        }

        fNoiseSeed[0] = 0.5f;
        PerlinNoise1D(terrainWidth, fNoiseSeed, 8, 2.0f, fSurface);

        for (int x = 0; x < terrainWidth; x++) {
            for (int y = 0; y < terrainHeight; y++) {
                if (y >= fSurface[x] * terrainHeight) {
                    map[y * terrainWidth + x] = 1;
                }
                else {
                    map[y * terrainWidth + x] = 0;
                }
            }
        }
        
        delete[] fSurface;
        delete[] fNoiseSeed;
    }

    void PerlinNoise1D(int nCount, float* fSeed, int nOctaves, float fBias, float* fOutput)
    {
        // Used 1D Perlin Noise
        for (int x = 0; x < nCount; x++)
        {
            float fNoise = 0.0f;
            float fScaleAcc = 0.0f;
            float fScale = 1.0f;

            for (int o = 0; o < nOctaves; o++)
            {
                int nPitch = nCount >> o;
                int nSample1 = (x / nPitch) * nPitch;
                int nSample2 = (nSample1 + nPitch) % nCount;
                float fBlend = (float)(x - nSample1) / (float)nPitch;
                float fSample = (1.0f - fBlend) * fSeed[nSample1] + fBlend * fSeed[nSample2];
                fScaleAcc += fScale;
                fNoise += fSample * fScale;
                fScale = fScale / fBias;
            }

            // Scale to seed range
            fOutput[x] = fNoise / fScaleAcc;
        }
    }
};
//const int terrainWidth = screenWidth;
//const int terrainHeight = screenHeight / 2;
//
//float perlinNoise[terrainWidth];
//
//void TerrainGenerate() {
//    for (int i = 0; i < terrainWidth; i++) {
//        perlinNoise[i] = (float)GetRandomValue(0, terrainHeight) / (float)terrainHeight;
//    }
//}
//
//void TerrainDraw() {
//    for (int i = 0; i < terrainWidth - 1; i++) {
//        DrawLine(i, screenHeight - perlinNoise[i] * screenHeight, i + 1, screenHeight - perlinNoise[i + 1] * screenHeight, GREEN);
//    }
//}

int main(void)
{
    //REZOLUCIJa ekrana

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    //GameStart();

    //Kreiranje tenka

    Tank tank1({ screenWidth / 4 - 20, screenHeight / 2 - 20 }, { 40, 40 }, 
        {0, 0}, 0, 0,
        {0, 0}, 0, 0,
        {0, 0}, false, true, YELLOW);
    Tank tank2({ 3 * screenWidth / 4 - 20, screenHeight / 2 - 20 }, { 40, 40 },
        { 0, 0 }, 0, 0,
        { 0, 0 }, 0, 0,
        { 0, 0 }, false, true, GREEN);

    //TerrainGenerate();
    Terrain terrain;

    //Staro Kreiranje tenka
    //Tank tank1(screenWidth / 4 - 20, screenHeight / 2 - 20, YELLOW, 200.0f, 100.0f, 400.0f, 3);
    //Tank tank2(3 * screenWidth / 4 - 20, screenHeight / 2 - 20, BLUE, 200.0f, 100.0f, 400.0f, 3);
    //Tank* activeTankTurn = &tank1;
    //int activeTankTurn = 1;
    //TurnTimer turnTimer(30.0);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        tank1.UpdateAiming();
        //tank2.UpdateAiming();

        BeginDrawing();
        ClearBackground(SKYBLUE);

        terrain.OnUserUpdate(GetFrameTime());

        tank1.TankDraw();
        tank2.TankDraw();
        //TerrainDraw();
        

        EndDrawing();

    }

    CloseWindow();

    return 0;
}

//void GameStart() {
//    Tank tank1();
//    Tank tank2();
//
//    //GenerateTerrain();
//
//}
//
//void GameUpdateStartPlayFrame() {
//    BeginDrawing();
//    ClearBackground(BLACK);
//    
//    for (int i = 0; i < 2; i++) {
//        
//    }
//}
