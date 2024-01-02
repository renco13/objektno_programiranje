#pragma once
#ifndef TURNTIMER_H
#define TURNTIMER_H

class TurnTimer {
public:
	TurnTimer(float duration);
	void Start();
	void Stop();
	bool Update();
	float GetTime() const;

private:
	float timerDuration;
	float timer;
	bool isRunning;
};

#endif
