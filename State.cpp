#include "State.h"

State::State()
	: timer(GameTimer()), num(0)
{
}

State::State(int n, Vector3 gravity, double damp)
	: num(n), timer(GameTimer()), gravity(gravity), damp(damp)
{
	this->entities = new Entity*[n];
}

State::State(Entity * entities[], int num, Vector3 gravity, double damp)
	: entities(entities), num(num), timer(GameTimer()), gravity(gravity), damp(damp)
{
}

State::~State()
{
	for (; num > 0; num--)
	{
		delete entities[num-1];
	}
	delete[] entities;

}

void State::setGravity(Vector3 gravity)
{
	this->gravity = gravity;
}

void State::setDamp(double damp)
{
	this->damp = damp;
}

void State::updateState()
{
	timer.calculateFrameTime();
	int count = 0;
	timer.findRemainder(count);
	double alpha = timer.accumulator / timer.dt;

	for (int i = 0; i < num; i++)
	{
		Derivative current = { entities[i]->position, entities[i]->momentum };
		while (count > 0)
		{
			integrate(entities[i], timer.t, timer.dt);
			count--;
		}
		current.velocity = current.velocity * alpha + entities[i]->position * (1 - alpha);
		current.force = current.force * alpha + entities[i]->velocity * (1 - alpha);
	}
}

void State::integrate(Entity* e, double t, double dt)
{
	Derivative a, b, c, d;
	a = evaluate(e, dt, Derivative{});
	b = evaluate(e, dt, Derivative{});
	c = evaluate(e, dt, Derivative{});
	d = evaluate(e, dt, Derivative{});

	float temp = 1 / 6;
	Vector3 dxdt = (a.velocity + (b.velocity + c.velocity) * 2.0f + d.velocity) * temp;

	e->position += dxdt * dt;
	e->updateMomentum(e->force, dt);
}

Derivative State::evaluate(Entity * initial, double dt, Derivative & d)
{
	initial->updateMomentum(initial->force, dt);
	return Derivative{ initial->velocity, initial->force };
}
