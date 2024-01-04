#pragma once
#ifndef TANK_H
#define TANK_H

#include "raylib.h"
#include "projectile.h"
#include "turntimer.h"

class Tank {

public:
	Tank(float x, float y, Color color, float speed, float aimSpeed,float shootSpeed, int alive);
	void Update();
	void Draw();
	void Move(int moveLeft, int moveRight);
	void Aim(int moveUp, int moveDown);
	void Shoot(int shootKey);
	int IsAlive();

	void DrawProjectile();

	//void StartTurn();
	//void EndTurn();
	//bool IsTurnActive() const;
	//float GetRemainingTime() const;

private:
	Rectangle body;
	Color tankColor;
	float tankSpeed;
	float aimSpeed;
	float shootSpeed;
	int tankAlive;

	Projectile projectile;
	Rectangle turret;

	//TurnTimer turnTime;
	//enum class TankState {
	//	idle,
	//	moving,
	//	shooting,
	//	waiting
	//};
	//TankState state;
	//const float moveTurnDuration = 0.0f;
	//const float shootTurnDuration = 0.0f;
	//const float extraTurnDuration = 0.0f;
	//float remainingTime;
	//bool isTurnActive;
};

#endif
