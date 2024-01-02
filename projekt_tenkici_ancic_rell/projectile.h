#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "raylib.h"

class Projectile {
public:
	Projectile(float x, float y, float speed , Color color);
	void Update();
	void Draw();
	bool IsActive() const;
	
private:
	Rectangle body;
	Color projectileColor;
	float projectileSpeed;
	bool active;
};

#endif
