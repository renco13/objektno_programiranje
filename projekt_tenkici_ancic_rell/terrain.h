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
    void DrawTank(float fOffsetX, float fOffsetY);

    unsigned char* GetMap() const {     // Za poziv u drugim klasama
        return map;
    }

    float GetCameraPosX() const { return fCameraPosX; }
    const float* GetSurface() const { return fSurface; }

private:
    // Velicina prozora
    const int ScreenWidth = 800;
    const int ScreenHeight = 600;

    // Velicina terraina
    int nMapWidth = 1200;
    int nMapHeight = 600;
    unsigned char* map = nullptr;

    // Default pozicije kamera
    float fCameraPosX = 0.0f;
    float fCameraPosY = 0.0f;

    // Varijable za pozicioniranje tenka na povrsinu terrain
    float tankX = 50.0f;
    float tankY = 0.0f;
    float* fSurface = nullptr;
};

#endif // !MAP_H
