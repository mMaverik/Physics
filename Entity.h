#pragma once
#include "Vector3.h"

typedef struct
{
	Vector3 velocity;
	Vector3 force;
} Derivative;

class Entity
{
public:
	Entity();
	Entity(Vector3 position, float mass);
	Entity(Vector3 position, Vector3 force, float mass);

	virtual ~Entity();

	Entity& inverseMass();

	Entity& recalculateVelocity();

	Entity& updateMomentum(Vector3 force, double dt);

	friend ostream& operator<<(ostream& output, Entity* entity);

	Vector3 position;
	Vector3 momentum;
	Vector3 velocity;
	Vector3 force;
	float mass;
	float inversemass;
};