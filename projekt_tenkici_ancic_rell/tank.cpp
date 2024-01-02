#include "tank.h"
#include "projectile.h"
#include "turntimer.h"
#include <iostream>
#include <string>

//Kreiranje tenka
Tank::Tank(float x, float y, Color color, float speed, float shootSpeed)
    : body({ x, y, 40, 40 }), turret({ x + 20, y, 10, 30 }),
    tankColor(color), tankSpeed(speed), shootSpeed(shootSpeed),
    projectile(turret.x + turret.width, turret.y + turret.height / 2, 400.0f, tankColor),
    turnTime(0.0f), state(Tank::TankState::idle),
    moveTurnDuration(10.0f), shootTurnDuration(10.0f), extraTurnDuration(5.0f), remainingTime(0.0f),
    isTurnActive(false) {}


void Tank::Update() {
	//Bilo kakve akcije u vezi tenkica idu ovdje
	//Move(KEY_A, KEY_D);
    //Move(KEY_LEFT, KEY_RIGHT);
    if (state != TankState::idle) {
        if (turnTime.Update()) {
            switch (state) {
            case TankState::moving:
                state = TankState::shooting;
                turnTime = TurnTimer(shootTurnDuration);
                break;
            case TankState::shooting:
                state = TankState::waiting;
                turnTime = TurnTimer(extraTurnDuration);
                break;
            case TankState::waiting:
                EndTurn();
                break;
            default:
                break;
            }
        }
    }
}

void Tank::Draw() {
	//graficki prikaz tenkica
	DrawRectangleRec(body, tankColor);
    DrawRectangleRec(turret, tankColor);

    //graficki prikaz preostalog vremena u tvojem potezu
    std::string timeString = std::to_string(turnTime.GetTime());
    const char* timeChar = timeString.c_str();
    DrawText(timeChar, 10, 10, 20, WHITE);
}

void Tank::Move(int moveLeft, int moveRight) {
	//micanje tenkica do rubova ekrana
    if (IsKeyDown(moveLeft) && body.x > 0) {
        body.x -= tankSpeed * GetFrameTime();
    }
    if (IsKeyDown(moveRight) && body.x + body.width < GetScreenWidth()) {
        body.x += tankSpeed * GetFrameTime();
    }
    turret.x = body.x + 15;
}
 
void Tank::Shoot(int shootKey) {
    //pucanje tenka
    if (IsKeyPressed(shootKey) && !projectile.IsActive()) {
        projectile = Projectile(turret.x + turret.width, turret.y + turret.height / 2, 400.0f , tankColor);
    }
    projectile.Update();
}

void Tank::DrawProjectile() {
    //poziv za graficki prikaz projektila
    projectile.Draw();
}

void Tank::StartTurn() {
    //timer za vremensko ogranicenje u tvojem potezu
    state = TankState::moving;
    turnTime = TurnTimer(moveTurnDuration);
    remainingTime = moveTurnDuration;
    isTurnActive = true;
}

void Tank::EndTurn() {
    state = TankState::idle;
    turnTime = TurnTimer(0.0f);
}

bool Tank::IsTurnActive() const {
    return isTurnActive;
}

float Tank::GetRemainingTime() const {
    return turnTime.GetTime();
}