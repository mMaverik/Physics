#pragma once
#include "Vector3.h"

Vector3::Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
	:dimensions{x,y,z}
{
	setMagnitudeSq();
}

Vector3::Vector3(Vector3& c)
	: dimensions{ c.dimensions[0], c.dimensions[1], c.dimensions[2] }
{
	setMagnitudeSq();
}

Vector3::~Vector3()
{
}

Vector3& Vector3::setX(float x)
{
	dimensions[0] = x;
	setMagnitudeSq();
	return *this;
}

Vector3& Vector3::setY(float y)
{
	dimensions[1] = y;
	setMagnitudeSq();
	return *this;
}

Vector3& Vector3::setZ(float z)
{
	dimensions[2] = z;
	setMagnitudeSq();
	return *this;
}

Vector3& Vector3::setMagnitudeSq()
{
	magnitudeSq = powf(dimensions[0], 2) + powf(dimensions[1], 2) + powf(dimensions[2], 2);
	return *this;
}

Vector3 Vector3::operator+(Vector3 rhs)
{
	return Vector3(
		dimensions[0] + rhs.dimensions[0],
		dimensions[1] + rhs.dimensions[1],
		dimensions[2] + rhs.dimensions[2]);
}

Vector3 Vector3::operator-(Vector3 rhs)
{
	return Vector3(
		dimensions[0] - rhs.dimensions[0],
		dimensions[1] - rhs.dimensions[1],
		dimensions[2] - rhs.dimensions[2]);
}

Vector3 Vector3::operator-()
{
	return Vector3(-dimensions[0], -dimensions[1], -dimensions[2]);
}

Vector3 Vector3::operator*(float s)
{
	return Vector3(
		dimensions[0] * s,
		dimensions[1] * s,
		dimensions[2] * s);
}

Vector3 Vector3::operator*(double s)
{
	return Vector3(
		dimensions[0] * s,
		dimensions[1] * s,
		dimensions[2] * s);
}

Vector3 Vector3::operator/(float s)
{
	float inverseS = 1 / s;
	return Vector3(
		dimensions[0] * inverseS,
		dimensions[1] * inverseS,
		dimensions[2] * inverseS);
}

Vector3 Vector3::operator/(double s)
{
	double inverseS = 1 / s;
	return Vector3(
		dimensions[0] * inverseS,
		dimensions[1] * inverseS,
		dimensions[2] * inverseS);
}

Vector3& Vector3::operator+=(Vector3 rhs)
{
	dimensions[0] += rhs.dimensions[0];
	dimensions[1] += rhs.dimensions[1];
	dimensions[2] += rhs.dimensions[2];
	setMagnitudeSq();
	return *this;
}

Vector3& Vector3::operator-=(Vector3 rhs)
{
	dimensions[0] += rhs.dimensions[0];
	dimensions[1] += rhs.dimensions[1];
	dimensions[2] += rhs.dimensions[2];
	setMagnitudeSq();
	return *this;
}

Vector3& Vector3::operator*=(float s)
{
	dimensions[0] *= s;
	dimensions[1] *= s;
	dimensions[2] *= s;
	setMagnitudeSq();
	return *this;
}

Vector3 & Vector3::operator*=(double s)
{
	dimensions[0] *= s;
	dimensions[1] *= s;
	dimensions[2] *= s;
	setMagnitudeSq();
	return *this;
}

Vector3& Vector3::operator/=(float s)
{
	float inverseS = 1 / s;
	dimensions[0] *= inverseS;
	dimensions[1] *= inverseS;
	dimensions[2] *= inverseS;
	setMagnitudeSq();
	return *this;
}

Vector3 & Vector3::operator/=(double s)
{
	float inverseS = 1 / s;
	dimensions[0] *= inverseS;
	dimensions[1] *= inverseS;
	dimensions[2] *= inverseS;
	setMagnitudeSq();
	return *this;
}

bool Vector3::operator==(Vector3 rhs)
{
	return dimensions[0] == rhs.dimensions[0]
		&& dimensions[1] == rhs.dimensions[1]
		&& dimensions[2] == rhs.dimensions[2];
}

bool Vector3::operator!=(Vector3 rhs)
{
	return dimensions[0] != rhs.dimensions[0]
		|| dimensions[1] != rhs.dimensions[1]
		|| dimensions[2] != rhs.dimensions[2];
}

float Vector3::magnitude()
{
	return sqrtf(magnitudeSq);
}

Vector3 Vector3::normalise()
{
	return (*this / magnitude());
}

float Vector3::dot(Vector3 rhs)
{
	return dimensions[0] * rhs.dimensions[0]
		+ dimensions[1] * rhs.dimensions[1]
		+ dimensions[2] * rhs.dimensions[2];
}

Vector3 Vector3::cross(Vector3 rhs)
{
	return Vector3(dimensions[1] * rhs.dimensions[2] - dimensions[2] * rhs.dimensions[1],
		dimensions[2] * rhs.dimensions[0] - dimensions[0] * rhs.dimensions[2],
		dimensions[0] * rhs.dimensions[1] - dimensions[1] * rhs.dimensions[0]);
}

ostream & operator<<(ostream & output, Vector3& v)
{
	output << "[" << v.dimensions[0] << "," << v.dimensions[1] << "," << v.dimensions[2] << ",(" << v.magnitudeSq << ")]";
	return output;
}
