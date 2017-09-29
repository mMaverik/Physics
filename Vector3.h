#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	Vector3(Vector3& c);

	~Vector3();

	Vector3& setX(float x);
	Vector3& setY(float y);
	Vector3& setZ(float z);
	Vector3& setMagnitudeSq();

	Vector3 operator+(Vector3 rhs);
	Vector3 operator-(Vector3 rhs);
	Vector3 operator-();
	Vector3 operator*(float s);
	Vector3 operator*(double s);
	Vector3 operator/(float s);
	Vector3 operator/(double s);
	Vector3& operator+=(Vector3 rhs);
	Vector3& operator-=(Vector3 rhs);
	Vector3& operator*=(float s);
	Vector3& operator*=(double s);
	Vector3& operator/=(float s);
	Vector3& operator/=(double s);
	bool operator==(Vector3 rhs);
	bool operator!=(Vector3 rhs);

	float magnitude();
	Vector3 normalise();
	float dot(Vector3 rhs);
	Vector3 cross(Vector3 rhs);

	friend ostream& operator<<(ostream& output, Vector3& v);


	float dimensions[3];
	float magnitudeSq;
};

