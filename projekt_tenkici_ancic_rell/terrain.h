#pragma once

#ifndef TERRAIN_H
#define TERRAIN_H
#include "raylib.h"

class TerrainGenerator {
public:
    TerrainGenerator();
    ~TerrainGenerator();

    virtual bool OnUserUpdate(float fElapsedTime);
    void CreateMap();
    void PerlinNoise1D(int nCount, float* fSeed, int nOctaves, float fBias, float* fOutput);
    void DrawTerrain();

private:
    // Velicina prozora
    const int ScreenWidth = 800;
    const int ScreenHeight = 600;

    // Velicina terraina
    int nMapWidth = 1600;
    int nMapHeight = 600;
    unsigned char* map = nullptr;

    // Default pozicije kamera
    float fCameraPosX = 0.0f;
    float fCameraPosY = 0.0f;
};

#endif // !MAP_H
