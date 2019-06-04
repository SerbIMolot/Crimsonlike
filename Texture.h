#ifndef TEXTURE_H
#define TEXTURE_H

#include "inc.h"
#include <memory>

class Texture {
	Sprite* sprite;


	int w;
	int h;

public:
	const char *str;
	Texture();
	Texture(const char* path);
	~Texture();
	
	void drawTexture(float x, float y);
	void drawTexture(Vector2d& vec);

	int getWight();
	int getHight();

};


#endif // !TEXTURE_H
