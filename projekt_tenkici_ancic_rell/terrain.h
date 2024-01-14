#pragma once

#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain{
public:


    //Terrain() {
    //    map = nullptr;
    //}
    //
    //~Terrain() {
    //    if (map != nullptr) {
    //        delete[] map;
    //        map = nullptr;
    //    }
    //}
    //
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
    //
    //    return true;
    //}
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
        //Used 1D Perlin Noise
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

            //Scale to seed range
            fOutput[x] = fNoise / fScaleAcc;
        }
    }
};

#endif // !TERRAIN_H
