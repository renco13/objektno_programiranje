#include <iostream>
#include "raylib.h"
#include "tank.h"
#include "projectile.h"
#include "turntimer.h"
#include <cmath>

//void GameMenu(); //trigger za glavni meni
//void GameSettings(); //trigger za postavke
//void GameQuit(); //trigger za izlazak iz igre
//void GameStart(); //trigger za graficko pokretanje igre
//void GameUpdatePlayFrame(); //trigger za update grafickog crtnja igre ili pokrecanja igra 

const int screenWidth = 800;
const int screenHeight = 450;

static void BuildingsGenerate(void);

#define MAX_BUILDINGS 15
#define BUILDING_RELATIVE_ERROR          30       
#define BUILDING_MIN_RELATIVE_HEIGHT     20        
#define BUILDING_MAX_RELATIVE_HEIGHT     60        
#define BUILDING_MIN_GRAYSCALE_COLOR    120        
#define BUILDING_MAX_GRAYSCALE_COLOR    200  

typedef struct Building {
    Rectangle rectangle;
    Color color;
}Building;

static Building building[MAX_BUILDINGS] = { 0 };

static void BuildingsGenerate(void) {
    //generiranje horizontalno
    int currentWidth = 0;

    float relativeWidth = 100 / (100 - BUILDING_RELATIVE_ERROR);
    float buildingWidthMean = (screenWidth * relativeWidth / MAX_BUILDINGS) + 1; // We add one to make sure we will cover the whole screen.

    int currentHeight = 0;
    int grayLevel;

    for (int i = 0; i < MAX_BUILDINGS; i++) {
        // Horizontal
        building[i].rectangle.x = static_cast<float>(currentWidth);
        building[i].rectangle.width = static_cast<float>(GetRandomValue(buildingWidthMean * (100 - BUILDING_RELATIVE_ERROR / 2) / 100 + 1, buildingWidthMean * (100 + BUILDING_RELATIVE_ERROR) / 100));

        currentWidth += static_cast<int>(building[i].rectangle.width);

        // Vertical
        currentHeight = GetRandomValue(BUILDING_MIN_RELATIVE_HEIGHT, BUILDING_MAX_RELATIVE_HEIGHT);
        building[i].rectangle.y = static_cast<float>(screenHeight - (screenHeight * currentHeight / 100));
        building[i].rectangle.height = static_cast<float>(screenHeight * currentHeight / 100 + 1);

        // Color
        grayLevel = GetRandomValue(BUILDING_MIN_GRAYSCALE_COLOR, BUILDING_MAX_GRAYSCALE_COLOR);
        building[i].color = Color{ static_cast<unsigned char>(grayLevel), static_cast<unsigned char>(grayLevel), static_cast<unsigned char>(grayLevel), 255 };
    }
}

static void DrawTestRectangle(void) {
    // Draw a single rectangle for testing purposes
    building[0].rectangle.x = 100;
    building[0].rectangle.y = 100;
    building[0].rectangle.width = 50;
    building[0].rectangle.height = 50;
    building[0].color = RED;

    DrawRectangleRec(building[0].rectangle, building[0].color);
}

//class Terrain {
//public:
//    Terrain() {
//        map = nullptr;
//    }
//
//    ~Terrain() {
//        if (map != nullptr) {
//            delete[] map;
//            map = nullptr;
//        }
//    }
//
//    virtual bool OnUserUpdate(float fElaspedTime) {
//        //ponovno generiranje zemlje
//        if (IsKeyPressed(KEY_M))
//            terrainCreate();
//
//        //crtanje neba
//        for (int x = 0; x < screenWidth; x++) {
//            for (int y = 0; y < screenHeight; y++) {
//                switch (map[(y)*terrainWidth + (x)]) {
//                case 0:
//                    DrawPixel(x, y, SKYBLUE);
//                    break;
//                case 1:
//                    DrawPixel(x, y, DARKGREEN);
//                    break;
//                }
//            }
//        }
//
//        return true;
//    }
//    //void UpdateTerrain(float fElapsedTime) {
//    //    OnUserUpdate(fElapsedTime);
//    //}
//private:
//    int terrainWidth = 1280;
//    int terrainHeight = 720;
//    unsigned char* map = nullptr;
//
//    virtual bool OnUserCreate() {
//        if (map != nullptr) {
//            delete[] map;
//            map = nullptr;
//        }
//
//        map = new unsigned char[terrainWidth * terrainHeight];
//        memset(map, 0, terrainWidth * terrainHeight * sizeof(unsigned char));
//        terrainCreate();
//
//        return true;
//    }
//
//    //virtual bool OnUserUpdate(float fElaspedTime) {
//    //    //ponovno generiranje zemlje
//    //    if (IsKeyPressed(KEY_M))
//    //        terrainCreate();
//    //    
//    //    //crtanje neba
//    //    for (int x = 0; x < screenWidth; x++) {
//    //        for (int y = 0; y < screenHeight; y++) {
//    //            switch (map[(y)*terrainWidth + (x)]) {
//    //            case 0:
//    //                DrawPixel(x, y, SKYBLUE);
//    //                break;
//    //            case 1:
//    //                DrawPixel(x, y, DARKGREEN);
//    //                break;
//    //            }
//    //        }
//    //    }
//
//    //    return true;
//    //}
//
//    void terrainCreate() {
//        float* fSurface = new float[terrainWidth];
//        float* fNoiseSeed = new float[terrainWidth];
//
//        for (int i = 0; i < terrainWidth; i++) {
//            fNoiseSeed[i] = (float)rand() / (float)RAND_MAX;
//        }
//
//        fNoiseSeed[0] = 0.5f;
//        PerlinNoise1D(terrainWidth, fNoiseSeed, 8, 2.0f, fSurface);
//
//        for (int x = 0; x < terrainWidth; x++) {
//            for (int y = 0; y < terrainHeight; y++) {
//                if (y >= fSurface[x] * terrainHeight) {
//                    map[y * terrainWidth + x] = 1;
//                }
//                else {
//                    map[y * terrainWidth + x] = 0;
//                }
//            }
//        }
//        
//        delete[] fSurface;
//        delete[] fNoiseSeed;
//    }
//
//    void PerlinNoise1D(int nCount, float* fSeed, int nOctaves, float fBias, float* fOutput)
//    {
//        // Used 1D Perlin Noise
//        for (int x = 0; x < nCount; x++)
//        {
//            float fNoise = 0.0f;
//            float fScaleAcc = 0.0f;
//            float fScale = 1.0f;
//
//            for (int o = 0; o < nOctaves; o++)
//            {
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
//};
////const int terrainWidth = screenWidth;
////const int terrainHeight = screenHeight / 2;
////
////float perlinNoise[terrainWidth];
////
////void TerrainGenerate() {
////    for (int i = 0; i < terrainWidth; i++) {
////        perlinNoise[i] = (float)GetRandomValue(0, terrainHeight) / (float)terrainHeight;
////    }
////}
////
////void TerrainDraw() {
////    for (int i = 0; i < terrainWidth - 1; i++) {
////        DrawLine(i, screenHeight - perlinNoise[i] * screenHeight, i + 1, screenHeight - perlinNoise[i + 1] * screenHeight, GREEN);
////    }
////}

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

    BuildingsGenerate();

    //TerrainGenerate();
    //Terrain terrain;

    //Staro Kreiranje tenka
    //Tank tank1(screenWidth / 4 - 20, screenHeight / 2 - 20, YELLOW, 200.0f, 100.0f, 400.0f, 3);
    //Tank tank2(3 * screenWidth / 4 - 20, screenHeight / 2 - 20, BLUE, 200.0f, 100.0f, 400.0f, 3);
    //Tank* activeTankTurn = &tank1;
    //int activeTankTurn = 1;
    //TurnTimer turnTimer(30.0);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BuildingsGenerate();

        tank1.UpdateAiming();
        //tank2.UpdateAiming();

        BeginDrawing();
        ClearBackground(SKYBLUE);

        DrawTestRectangle();

        //terrain.OnUserUpdate(GetFrameTime());

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
