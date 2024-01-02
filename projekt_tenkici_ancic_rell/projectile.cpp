#include "projectile.h"

Projectile::Projectile(float x, float y, float speed, Color color)
	: body({ x, y, 10, 10 }), projectileSpeed(speed), projectileColor(color), active(true) {}

void Projectile::Update() {
	if (active) {
		body.x += projectileSpeed * GetFrameTime();
	}
	if (body.x > GetScreenWidth()) {
		active = false;
	}
}

void Projectile::Draw() {
	if (active) {
		DrawRectangleRec(body, projectileColor);
	}
}

bool Projectile::IsActive() const {
	return active;
}