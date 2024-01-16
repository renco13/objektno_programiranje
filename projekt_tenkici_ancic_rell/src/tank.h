#pragma once

#ifndef TANK_H
#define TANK_H

#include "physics.h"
#include "terrain.h"

class Tank : public Physics {
public:
    Tank(float initX, float initY, TerrainGenerator& terrain);
    ~Tank();
    void Draw(float offsetX, float offsetY);
    void Update(float fElapsedTime);

    virtual bool OnUserUpdate(float fElapsedTime);
    float fShootingAngle = 0.0f;
    void SetCrosshair(float crosshairX, float crosshairY);
    void DrawCrosshair(float x, float y, float size);
    //void DrawShotPowerBar(float offsetX, float offsetY);
    void UpdateShotPower(float fElapsedTime);
    void DrawChargingBar(float barWidth);

private:
    int nMapWidth = 800;
    int nMapHeight = 600;
    float x, y;
    Physics physics;
    float radius = 4.0f;
    bool bStable;
    Texture2D tankTexture;
    TerrainGenerator& terrain;
    float crosshairX;
    float crosshairY;
    float shotPower;
    bool chargingShot;
    float maxShotPower = 5.0f;
    float barOffsetY = -25.0f;
    bool fireWeapon = false;
    //int nBounceBeforeDeath;
    //bool bDead;
};


#endif // !TANK_H
