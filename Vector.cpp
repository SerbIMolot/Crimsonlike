#include "Vector.h"

Vector2d::Vector2d()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2d::Vector2d(int x, int y) {
	this->x = (float)x;
	this->y = (float)y;
}

Vector2d::~Vector2d() {
}

float Vector2d::getX() {
	return this->x;
}

float Vector2d::getY() {
	return this->y;
}

float Vector2d::getX() const
{
	return this->x;
}

float Vector2d::getY() const
{
	return this->y;
}

void Vector2d::setX(float x)
{
	this->x = x;
}

void Vector2d::setY(float y) {
	this->y = y;
}

float Vector2d::length() {
	return sqrt((x*x) + (y*y));
}

float Vector2d::lengthSqr() {
	return (x*x) + (y*y);
}

void Vector2d::normalise() {
	float length = this->length();
	if (length > 0) {
		*this *= 1 / length;
	}
} 

Vector2d RotateVector(Vector2d& vec, float angle) {
	float radAngle = (float)(angle*DEG_TO_RAD);

	return Vector2d((float)(vec.getX() * cos(radAngle) - vec.getY() * sin(radAngle)), (float)(vec.getX() * sin(radAngle) + vec.getY() * cos(radAngle)));
}

Vector2d Vector2d::operator+(Vector2d& r) {
	return Vector2d(this->x + r.x, this->y + r.y);
}

Vector2d Vector2d::operator-(Vector2d& r)  {
	return Vector2d(this->x - r.x, this->y - r.y);
}

Vector2d& Vector2d::operator+=(Vector2d& r) {
	this->x += r.x;
	this->y += r.y;

	return *this;
}

Vector2d& Vector2d::operator-=(Vector2d& r) {
	this->x -= r.x;
	this->y -= r.y;

	return *this;
}

Vector2d Vector2d::operator+(const Vector2d& r) {
	return Vector2d(this->x + r.x, this->y + r.y);
}

Vector2d Vector2d::operator-(const Vector2d& r) {
	return Vector2d(this->x - r.x, this->y - r.y);
}

Vector2d& Vector2d::operator+=(const Vector2d& r) {
	this->x += r.x;
	this->y += r.y;

	return *this;
}

Vector2d& Vector2d::operator-=(const Vector2d& r) {
	this->x -= r.x;
	this->y -= r.y;

	return *this;
}

Vector2d Vector2d::operator*(float scalar) {
	return Vector2d(x*scalar, y*scalar);
}

Vector2d & Vector2d::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;

	return *this;
}
Vector2d Vector2d::operator/(float scalar) {
	return Vector2d(x/scalar, y/scalar);
}

Vector2d & Vector2d::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;

	return *this;
}

std::ostream & operator<<(std::ostream & out, const Vector2d & vec) {
	out << "(" << vec.x << "," << vec.y << ")";
	return out;
}
