#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <iostream>

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f

class Vector2d {
	float x;
	float y;
public:
	Vector2d();
	Vector2d(float x, float y);
	Vector2d(int x, int y);

	~Vector2d();

	float getX();
	float getY();
	float getX() const;
	float getY() const;

	void setX(float x);
	void setY(float y);

	float length();
	float lengthSqr();

	void normalise();


	Vector2d operator+(Vector2d& r);
	Vector2d operator-(Vector2d& r);
	Vector2d& operator+=(Vector2d& r);
	Vector2d& operator-=(Vector2d& r);

	Vector2d operator+(const Vector2d& r);
	Vector2d operator-(const Vector2d& r);
	Vector2d& operator+=(const Vector2d& r);
	Vector2d& operator-=(const Vector2d& r);

	Vector2d operator*(float scalar);
	Vector2d& operator*=(float scalar);
	Vector2d operator/(float scalar);
	Vector2d& operator/=(float scalar);

	friend std::ostream& operator<<(std::ostream& out, const Vector2d& vec);
};

Vector2d RotateVector(Vector2d & vec, float angle);

const Vector2d vecUP = Vector2d(0.0f,-1.0f);
const Vector2d vecDOWN = Vector2d(0.0f,1.0f);
const Vector2d vecRIGHT = Vector2d(1.0f,0.0f);
const Vector2d vecLEFT = Vector2d(-1.0f,0.0f);


#endif
