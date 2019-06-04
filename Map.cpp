#include "inc.h"

Vector2d Map::size = Vector2d();

Map::Map(float x, float y) {
	size = Vector2d(x, y);
}

Map::~Map() {
	textures.clear();
	for (auto t : tiles) {
		delete t;
	}
	tiles.clear();
}

void Map::Init() {
	cam = Camera::Instance();

	textures.push_back(TextureManager::getTexture("Floor.png"));
	textures.push_back(TextureManager::getTexture("Background.png"));
	
	int screenX, screenY;
	int tileNumX = 0, tileNumY = 0;
	float tempMapX = size.getX();
	float tempMapY = size.getY();

	getScreenSize(screenX, screenY);

	while (screenX > tileWidth || tempMapX > tileWidth) {
		screenX -= static_cast<int>(tileWidth);
		tempMapX -= static_cast<int>(tileWidth);
		tileNumX++;
	}
	tileNumX++;
	
	while (screenY > tileHeight || tempMapY > tileWidth) {
		screenY -= static_cast<int>(tileHeight);
		tempMapY -= static_cast<int>(tileHeight);
		tileNumY++;
	}
	tileNumY++;

	totalTiles = tileNumX * tileNumY;
	
	Generate(static_cast<int>(size.getX()), static_cast<int>(size.getY()));

}

void Map::Generate(int x, int y) {
	int tX = 0, tY = 0; // num of tiles at X coordinate and Y

	for (int t = 0; t < totalTiles; t++) {

		tiles.push_back(new Tile(static_cast<float>(tX), static_cast<float>(tY),textures[0], tUndefined));
		
		tX += TILE_WIDTH;

		if (tX > size.getX()) {
			if (tX < cam->getBox()->w) {
				continue;
			}
			tX = 0;
			tY += TILE_HEIGHT;
		}
	}
}

void Map::draw() {
	for (auto t : tiles) {
		t->draw();
	}
}

void Map::Update() {
}

Vector2d& Map::getMapSize() {
	return size;
}

int Map::id = 0;

Tile::Tile(float x, float y, Texture* texture, int type) {
	box = new Rect(x, y, TILE_WIDTH, TILE_HEIGHT);
	this->texture = texture;
	this->type = type;
}

Tile::Tile(Vector2d vec, Texture* texture, int type) {
	box = new Rect(vec.getX(), vec.getY(), TILE_WIDTH, TILE_HEIGHT);
	this->texture = texture;
	this->type = type;
}

Tile::~Tile() {
	delete box;
}

void Tile::draw() {
	if (collisionCheck(Camera::Instance(), this)) {
		texture->drawTexture(box->getVec() - Camera::Instance()->Pos());
	}
}

int Tile::getType() {
	return type;
}

Rect* Tile::getBox() {
	return box;
}

