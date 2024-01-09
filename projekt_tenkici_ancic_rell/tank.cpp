#include "tank.h"
#include "projectile.h"
#include "turntimer.h"
#include <iostream>
#include <string>

Tank::Tank(Vector2 position, Vector2 size,
	Vector2 aimCurrent, int aimAngleCurrent, int aimPowerCurrent,
	Vector2 aimPrevious, int aimPreviousAngle, int aimPowerPrevious,
	Vector2 impactArea, bool isPlayerTwo, bool alive, Color color)
	: tankPosition(position), tankSize(size),
	tankAimCurrent(aimCurrent), tankAimAngleCurrent(aimAngleCurrent), tankAimPowerCurrent(aimPowerCurrent),
	tankAimPrevious(aimPrevious), tankAimAnglePrevious(aimPreviousAngle), tankAimPowerPrevious(aimPowerPrevious),
	tankIsPlayerTwo(isPlayerTwo), tankIsAlive(true), tankColor(color) {}

void Tank::TankDraw() {
	Rectangle tankBody = {
		tankPosition.x - tankSize.x / 2, tankPosition.y - tankSize.y / 2, tankSize.x, tankSize.y };
	DrawRectangleRec(tankBody, tankColor);
	TankDrawAiming();
}

void Tank::TankDrawAiming() {
	Vector2 t1 = {
		tankPosition.x - tankSize.x / 4, tankIsPlayerTwo ? tankPosition.y + tankSize.y / 4 : tankPosition.y - tankSize.y / 4 };
	Vector2 t2 = {
		tankPosition.x + tankSize.x / 4, tankIsPlayerTwo ? tankPosition.y - tankSize.y / 4 : tankPosition.y + tankSize.y / 4 };
	DrawTriangle(t1, t2, tankAimPrevious, GRAY);
	DrawTriangle(t1, t2, tankAimCurrent, tankIsPlayerTwo ? PINK : GREEN);
}

void Tank::UpdateAiming() {
	Vector2 mousePosition = GetMousePosition();
	tankAimCurrent = mousePosition;

	//if (IsKeyDown(KEY_W)) {
	//	tankAimCurrent.y -= 20.0f;
	//}
	//else if (IsKeyDown(KEY_S)) {
	//	tankAimCurrent.y += 20.0f;
	//}

	if (mousePosition.y <= tankPosition.y) {
		if (tankIsPlayerTwo && mousePosition.x >= tankPosition.x) {
			tankAimPowerCurrent = sqrt(pow(tankPosition.x - mousePosition.x, 2) + pow(tankPosition.y - mousePosition.y, 2));
			tankAimAngleCurrent = asin((tankPosition.y - mousePosition.y) / tankAimPowerCurrent) * RAD2DEG;
		}
	}

	//tankAimCurrent = tankPosition;
}

void Tank::Shoot() {
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !tankIsShooting) {
		//tankAimPowerCurrent = Vector2Distance(tankAimCurrent, tankPosition);
		tankAimAngleCurrent = atan2(tankAimCurrent.y - tankPosition.y, tankAimCurrent.x - tankPosition.x) * RAD2DEG;
		tankIsShooting = true;

	}
}

Vector2 Tank::TankGetAimingPoint() const {
	return tankAimCurrent;
}

float Tank::TankGetAimingAngle() const {
	return atan2(tankAimPrevious.y - tankAimCurrent.y, tankAimPrevious.x - tankAimCurrent.x) * RAD2DEG;
}

float Tank::TankGetAimingPower() const {
	return tankAimPowerCurrent;
}

////Kreiranje tenka
//Tank::Tank(float x, float y, Color color, float speed, float aimSpeed, float shootSpeed, int alive)
//    : body({ x, y, 40, 40 }), turret({ x + 20, y, 10, 30 }),
//    tankColor(color), tankSpeed(speed), aimSpeed(aimSpeed), shootSpeed(shootSpeed), tankAlive(alive),
//    projectile(turret.x + turret.width, turret.y + turret.height / 2, 400.0f, tankColor) {}
////state(Tank::TankState::idle) {}
////turnTime(0.0f), state(Tank::TankState::idle) {}
////moveTurnDuration(10), shootTurnDuration(10), extraTurnDuration(5), remainingTime(0.0f),
////isTurnActive(false) {}
//
//
//void Tank::Update() {
//    //Bilo kakve akcije u vezi tenkica idu ovdje
//    Move(KEY_A, KEY_D);
//    Aim(KEY_W, KEY_S);
//    Shoot(KEY_SPACE);
//
//    //if (state != TankState::idle) {
//    //    if (turnTime.Update()) {
//    //        switch (state) {
//    //        case TankState::moving:
//    //            state = TankState::shooting;
//    //            turnTime = TurnTimer(shootTurnDuration);
//    //            break;
//    //        case TankState::shooting:
//    //            state = TankState::waiting;
//    //            turnTime = TurnTimer(extraTurnDuration);
//    //            break;
//    //        case TankState::waiting:
//    //            EndTurn();                                                                
//    //            break;
//    //        default:
//    //            break;
//    //        }
//    //    }
//    //}
//
//}
//
//void Tank::Draw() {
//    //graficki prikaz tenkica
//    DrawRectangleRec(body, tankColor);
//    DrawRectangleRec(turret, tankColor);
//
//    //graficki prikaz preostalog vremena u tvojem potezu
//    //std::string timeString = std::to_string(turnTime.GetTime());
//    //const char* timeChar = timeString.c_str();
//    //DrawText(timeChar, 10, 10, 20, WHITE);
//
//}
//
//void Tank::Move(int moveLeft, int moveRight) {
//    //micanje tenkica do rubova ekrana
//    if (IsKeyDown(moveLeft) && body.x > 0) {
//        body.x -= tankSpeed * GetFrameTime();
//    }
//    if (IsKeyDown(moveRight) && body.x + body.width < GetScreenWidth()) {
//        body.x += tankSpeed * GetFrameTime();
//    }
//    turret.x = body.x + 15;
//}
//
//void Tank::Aim(int moveUp, int moveDown) {
//    if (IsKeyDown(moveUp) && turret.y > 0) {
//        turret.y -= aimSpeed * GetFrameTime();
//        if (IsKeyDown(moveDown) && turret.y + turret.height < GetScreenHeight()) {
//            turret.y += aimSpeed * GetFrameTime();
//        }
//    }
//}
//
//void Tank::Shoot(int shootKey) {
//    //pucanje tenka
//    if (IsKeyPressed(shootKey) && !projectile.IsActive()) {
//        projectile = Projectile(turret.x + turret.width, turret.y + turret.height / 2, 400.0f, tankColor);
//    }
//    projectile.Update();
//}
//
//int Tank::IsAlive() {
//    return  --tankAlive;
//}
//
//void Tank::DrawProjectile() {
//    //poziv za graficki prikaz projektila
//    projectile.Draw();
//}
//
////void Tank::StartTurn() {
////    //timer za vremensko ogranicenje u tvojem potezu
////    state = TankState::moving;
////    turnTime = TurnTimer(moveTurnDuration);
////    remainingTime = moveTurnDuration;
////    isTurnActive = true;
////}
////
////void Tank::EndTurn() {
////    state = TankState::idle;
////    turnTime = TurnTimer(0.0f);
////}
////
////bool Tank::IsTurnActive() const {
////    return isTurnActive;
////}
////
////float Tank::GetRemainingTime() const {
////    return turnTime.GetTime();
////}
