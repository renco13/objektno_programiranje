#pragma once

#ifndef PHYSICS_H
#define PHYSISC_H

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
    bool bDead = false;
    int nBounceBeforeDeath = 0;
};

#endif // !PHYSICS_H

