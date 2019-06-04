#include "inc.h"
Rect::Rect() { 
	x = 0;
	y = 0;
	w = 0;
	h = 0;
}

Rect::Rect(int x, int y, int w, int h) {
	this->x = static_cast<float>(x);
	this->y = static_cast<float>(y);
	this->w = static_cast<float>(w);
	this->h = static_cast<float>(h);
}

Rect::Rect(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Rect::Rect(Vector2d vec, Texture* texture) {

	x = vec.getX();
	y = vec.getY();
	if (texture == nullptr) {
		w = 0;
		h = 0;
	} else {
		w = static_cast<float>(texture->getWight());
		h = static_cast<float>(texture->getHight());
	}
}

Rect::~Rect() { }

Vector2d Rect::getVec()
{
	return Vector2d(x, y);
}

void Rect::setVec(Vector2d& vec) {
	x = vec.getX();
	y = vec.getY();
}

float Rect::topSide()
{
	return y;
}

float Rect::BottomSide()
{
	return y + h;
}

float Rect::LeftSide()
{
	return x;
}

float Rect::RightSide()
{
	return x + w;
}
