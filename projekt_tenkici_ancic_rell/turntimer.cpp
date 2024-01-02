#include "raylib.h"
#include "turntimer.h"

TurnTimer::TurnTimer(float duration)
	: timerDuration(duration), timer(0.0f), isRunning(false) {}

void TurnTimer::Start() {
	isRunning = true;
	timer = timerDuration;
}

void TurnTimer::Stop() {
	isRunning = false;
	timer = 0.0f;
}

bool TurnTimer::Update() {
	if (isRunning) {
		timer -= GetFrameTime();
		if (timer <= 0.0f) {
			timer = 0.0f;
			isRunning = false;
			return true;
		}
	}
	return false;
}

float TurnTimer::GetTime() const {
	return timer;
}