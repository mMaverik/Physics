#pragma once
#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(Vector3 position, float mass)
	: position(position), mass(mass)
{
	inverseMass();
	updateMomentum(Vector3(0, 0, 0), 0.0);
}

Entity::Entity(Vector3 position, Vector3 force, float mass)
	: position(position), force(force), mass(mass)
{
	inverseMass();
	updateMomentum(force, 0.0);
}

Entity::~Entity()
{
}

Entity & Entity::inverseMass()
{
	inversemass = 1 / mass;
	return *this;
}

Entity & Entity::recalculateVelocity()
{
	velocity = momentum * inversemass;
}

Entity & Entity::updateMomentum(Vector3 force, double dt)
{
	momentum += force * dt;
	recalculateVelocity();
}

ostream& operator<<(ostream& output, Entity* entity)
{
	output << "{ " 
		<< entity->position 
		<< " , " 
		<< entity->momentum 
		<< " , " 
		<< entity->velocity 
		<< " , " 
		<< entity->mass 
		<< " }";
	return output;
}