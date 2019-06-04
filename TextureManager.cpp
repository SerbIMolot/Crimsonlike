#include "inc.h"

TextureManager* TextureManager::tmInstance = nullptr;
std::map<std::string, Texture*> TextureManager::Textures;

TextureManager::TextureManager() {

}


TextureManager::~TextureManager() {
	Close("all");
}

void TextureManager::Initialize(const char * path) {
	std::string temp = path;
	std::string fileName = temp.substr(temp.find_last_of("/") + 1, temp.size());

	
	Textures[fileName] = new Texture(path);
}

TextureManager* TextureManager::Instance() {
	if (tmInstance == nullptr) {

		tmInstance = new TextureManager();
		tmInstance->loadTextures();
	}
	return tmInstance;
}

void TextureManager::Close(std::string fileName) {
	for (auto t : Textures) {
		if (t.first == fileName) {
			delete t.second;
			Textures.erase(fileName);
		}
		if (fileName == "all") {
			delete t.second;
		}
	}
	if (fileName == "all") {
		Textures.clear();
	}
}

Texture * TextureManager::getTexture(const char * fileName) {	
	if (Textures.find(fileName) == Textures.end()) {
		return nullptr;
	} else {
	return Textures[fileName];
	}
}

void TextureManager::loadTextures() {
	Initialize("Data/bullet.png");
	Initialize("Data/avatar.jpg");
	Initialize("Data/en1.png");
	Initialize("Data/Scope1.png");
	Initialize("Data/Floor.png");
}
