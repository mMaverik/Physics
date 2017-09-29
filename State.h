#pragma once
#include "Entity.h"
#include "GameTimer.h"


class State
{
public:
	State();
	State(int n, Vector3 gravity, double damp);
	State(Entity* entities[], int num, Vector3 gravity, double damp);
	~State();

	void setGravity(Vector3 gravity);
	void setDamp(double damp);
	void updateState();

	void integrate(Entity* entity, double t, double dt);
	Derivative evaluate(Entity* initial, double dt, Derivative& d);

	Entity** entities;
	GameTimer timer;
	Vector3 gravity;
	double damp;
	int num;
};

