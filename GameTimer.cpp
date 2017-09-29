#pragma once
#include "GameTimer.h"

GameTimer::GameTimer()
	: t(0.0), dt(0.1), currentTime(0.0), accumulator(0.0)
{
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
}

GameTimer::~GameTimer()
{
}

double GameTimer::getTime()
{
	LARGE_INTEGER t;
	QueryPerformanceCounter(&t);
	return (double)((t.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart);
}

void GameTimer::calculateFrameTime()
{
	double newTime = getTime();
	double frameTime = newTime - currentTime;
	if (frameTime > 0.25)
		frameTime = 0.25;
	currentTime = newTime;
	accumulator += frameTime;
}

void GameTimer::findRemainder(int & count)
{
	while (accumulator >= dt)
	{
		count++;
		t += dt;
		accumulator -= dt;
	}
}
