#include "projectile.h"

Projectile::Projectile(Vector2 position, Vector2 speed, Color color)
	: projectileBody({ position.x, position.y, 10, 10 }), 
	projectilePosition(position), projectileSpeed(speed), projectileColor(color), active(true) {}

void Projectile::Update() {
	if (active) {
		projectileBody.x += projectileSpeed.x * GetFrameTime();
	}
	if (projectileBody.x > GetScreenWidth()) {
		active = false;
	}
}

void Projectile::Draw() {
	if (active) {
		DrawRectangleRec(projectileBody, RED);
	}
}

bool Projectile::IsActive() const {
	return active;
}	
