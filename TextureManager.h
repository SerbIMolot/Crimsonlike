#pragma once
#include "inc.h"
class TextureManager {
	static TextureManager* tmInstance;

	static std::map<std::string, Texture*> Textures;

	TextureManager();
	~TextureManager();
public:

	void Initialize(const char* path);

	static TextureManager* Instance();
	static void Close(std::string fileName);
	
	static Texture* getTexture(const char * fileName);
	void loadTextures();
};

