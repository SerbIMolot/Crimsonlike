#ifndef MAP_H
#define MAP_H

#include "inc.h"

#define TILE_WIDTH 64.0f
#define TILE_HEIGHT 61.0f
#define TOTAL_TILES 6.0f
#define TILE_TEXTURES 1.0f



enum TileType {
	GRASS
};

class Tile {
	Rect* box;
	Texture* texture;
	int type;
public:

	Tile(float x, float y, Texture * texture, int type);
	Tile(Vector2d vec, Texture * texture, int type);

	~Tile();

	void draw();

	int getType();

	Rect* getBox();
};

class Map {
	const float tileWidth = 64.0f;
	const float tileHeight = 61.0f;
	int totalTiles = 0;

	
	Camera* cam;

	std::vector<Tile*> tiles;
	std::vector<Texture*> textures;

	static Vector2d size;

	static int id;
public:
	Map();
	Map(float x, float y);
	~Map();

	void Init();

	void Generate(int x, int y);

	void draw();

	void Update();

	static Vector2d& getMapSize();
};


#endif