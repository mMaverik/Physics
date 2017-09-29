#pragma once
#include "Windows.h"

class GameTimer
{
public:
	GameTimer();
	~GameTimer();

	double getTime();
	void calculateFrameTime();
	void findRemainder(int& count);

	double t;
	double dt;
	double currentTime;
	double accumulator;
	LARGE_INTEGER frequency;
	LARGE_INTEGER start;
};