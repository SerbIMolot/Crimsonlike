#include "inc.h"


Texture::Texture() : str("std") 
{
	sprite = nullptr;
	w = 0;
	h = 0;

}

Texture::Texture(const char* path) :  str(path) 
{

	sprite = createSprite(path);

	getSpriteSize(sprite,w,h);

}

Texture::~Texture() {

			destroySprite(sprite);

			sprite = nullptr;
			w = 0;
			h = 0;
}


void Texture::drawTexture(float x, float y) 
{
	drawSprite(sprite, (int)x, (int)y);
}

void Texture::drawTexture(Vector2d &vec) 
{
	drawSprite(sprite, (int)vec.getX(), (int)vec.getY());
}

int Texture::getWight()
{
	return w;
}

int Texture::getHight()
{
	return h;
}
