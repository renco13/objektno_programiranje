#pragma once
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "raylib.h"

class Projectile {
public:
	Projectile(Vector2 position, Vector2 speed, Color color);
	void Update();
	void Draw();
	bool IsActive() const;

private:
	Rectangle projectileBody;
	Vector2 projectilePosition;
	Vector2 projectileSpeed;
	Color projectileColor;
	bool active;
};

#endif
