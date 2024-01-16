#pragma once

#ifndef DEBRIS_H
#define DEBRIS_H

#include "physics.h"
#include "terrain.h"
#include <vector>

class Debris : public Physics {
public:
    Debris(int nMapWidth, int nMapHeight, float x, float y, TerrainGenerator& terrain);

    void Update(float fElapsedTime);

    void Draw(float offsetX, float offsetY);

    virtual int BounceDeathAction() {
        return 0;
    }

    virtual bool OnUserUpdate(float fElapsedTime);

private:
    int nMapWidth = 1200;
    int nMapHeight = 800;
    Physics physics;
    TerrainGenerator& terrain;
    std::vector<Debris> debris;
};

#endif // !DEBRIS_H
