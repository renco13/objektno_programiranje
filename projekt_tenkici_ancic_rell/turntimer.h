#pragma once
#ifndef TURNTIMER_H
#define TURNTIMER_H

#include <chrono>
#include <thread>

class TurnTimer {
public:
	TurnTimer(double seconds);
	void Start();
	bool IsTimeUp() const;
	double GetRemainingTime() const;

private:
	std::chrono::steady_clock::time_point startTime;
	std::chrono::duration<double> turnDuration;
};

#endif
