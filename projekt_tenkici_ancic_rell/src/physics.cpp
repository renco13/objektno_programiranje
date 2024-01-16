#include "physics.h"

Physics::Physics() :
    px(0.0f), py(0.0f), vx(0.0f), vy(0.0f), ax(0.0f), ay(0.0f),
    radius(4.0f), bStable(false), friction(0.0f), bDead(false), nBounceBeforeDeath(0) {}
