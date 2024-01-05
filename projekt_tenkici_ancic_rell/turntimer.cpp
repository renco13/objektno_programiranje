#include "raylib.h"
#include "turntimer.h"

TurnTimer::TurnTimer(double seconds)
	: turnDuration(seconds) {}

void TurnTimer::Start() {
	startTime = std::chrono::steady_clock::now();
}

bool TurnTimer::IsTimeUp() const {
	auto currentTime = std::chrono::steady_clock::now();
	return (currentTime - startTime) >= turnDuration;
}

double TurnTimer::GetRemainingTime() const {
	auto currentTime = std::chrono::steady_clock::now();
	auto elapsed = currentTime - startTime;
	double remainingTime = std::max(0.0, turnDuration.count() - elapsed.count());
	return remainingTime;
}
