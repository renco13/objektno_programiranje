#include "raylib.h"
#include "terrain.h"
#include <cstdlib>

TerrainGenerator::TerrainGenerator() {
    map = new unsigned char[nMapWidth * nMapHeight];
}

TerrainGenerator::~TerrainGenerator() {
    delete[] map;
}

bool TerrainGenerator::OnUserUpdate(float fElapsedTime) {
    // Generating new random map with M
    if (IsKeyReleased(KEY_M))
        CreateMap();

    // Scrolling after mouse hits edge of screen
    float fMapScrollSpeed = 400.0f;
    // Povecan area registracije da je mis na rubu ekrana
    float fScrollArea = 50.0f;
    // Smoothing
    float fSpeedX = 0.0f;
    float fSpeedY = 0.0f;
    // X
    if (GetMouseX() < fScrollArea) {
        fSpeedX = (fScrollArea - GetMouseX()) / fScrollArea * fMapScrollSpeed;
        fCameraPosX -= fSpeedX * fElapsedTime;
    }
    if (GetMouseX() > ScreenWidth - fScrollArea) {
        fSpeedX = (GetMouseX() - (ScreenWidth - fScrollArea)) / fScrollArea * fMapScrollSpeed;
        fCameraPosX += fSpeedX * fElapsedTime;
    }
    // Y
    if (GetMouseY() < fScrollArea) {
        fSpeedY = (fScrollArea - GetMouseY()) / fScrollArea * fMapScrollSpeed;
        fCameraPosY -= fSpeedY * fElapsedTime;
    }
    if (GetMouseY() > ScreenHeight - fScrollArea) {
        fSpeedY = (GetMouseY() - (ScreenHeight - fScrollArea)) / fScrollArea * fMapScrollSpeed;
        fCameraPosY += fSpeedY * fElapsedTime;
    }

    // Clamp map boundaries
    if (fCameraPosX < 0) fCameraPosX = 0;
    if (fCameraPosX >= nMapWidth - ScreenWidth) fCameraPosX = nMapWidth - ScreenWidth;
    if (fCameraPosY < 0) fCameraPosY = 0;
    if (fCameraPosY >= nMapHeight - ScreenHeight) fCameraPosY = nMapHeight - ScreenHeight;

    return true;
}

void TerrainGenerator::CreateMap() {
    // Used 1D Perlin Noise
    float* fSurface = new float[nMapWidth];
    float* fNoiseSeed = new float[nMapWidth];

    // Populate with noise
    for (int i = 0; i < nMapWidth; i++)
        fNoiseSeed[i] = (float)rand() / (float)RAND_MAX;

    // Clamp noise to half way up screen
    fNoiseSeed[0] = 0.5f;

    // Generate 1D map
    PerlinNoise1D(nMapWidth, fNoiseSeed, 8, 2.0f, fSurface);

    // Fill 2D map based on adjacent 1D map
    for (int x = 0; x < nMapWidth; x++)
        for (int y = 0; y < nMapHeight; y++) {
            if (y >= fSurface[x] * nMapHeight)
                map[y * nMapWidth + x] = 1;
            else
                map[y * nMapWidth + x] = 0;
        }

    // Clean up!
    delete[] fSurface;
    delete[] fNoiseSeed;
}

// Taken from Perlin Noise Video https://youtu.be/6-0UaeJBumA
void TerrainGenerator::PerlinNoise1D(int nCount, float* fSeed, int nOctaves, float fBias, float* fOutput) {
    // Used 1D Perlin Noise
    for (int x = 0; x < nCount; x++) {
        float fNoise = 0.0f;
        float fScaleAcc = 0.0f;
        float fScale = 1.0f;

        for (int o = 0; o < nOctaves; o++) {
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

void TerrainGenerator::DrawTerrain() {
    for (int x = 0; x < nMapWidth; x++) {
        for (int y = 0; y < nMapHeight; y++) {

            // Porjvera je li unutar bounds STARO NE TREBA AKO JE nMapHeight 600
            //int mapX = static_cast<int>(fCameraPosX) + x;
            //int mapY = static_cast<int>(fCameraPosY) + y;

            // Provjera je li unutar bounds
            //if (mapX >= 0 && mapX < nMapWidth && mapY >= 0 && mapY < nMapHeight) {
            //    if (map[(y + (int)fCameraPosY) * nMapWidth + (x + (int)fCameraPosX)]) {
            //        // Draw terrain block at (x, y)
            //        DrawRectangle(x, y, 1, 1, DARKGREEN);
            //    }
            //}

            if (map[(y + (int)fCameraPosY) * nMapWidth + (x + (int)fCameraPosX)] == 1) {
                // Draw terrain block at (x, y)
                DrawRectangle(x, y, 1, 1, DARKGREEN);
            }
        }
    }
}