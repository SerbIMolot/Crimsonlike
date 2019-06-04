#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include "inc.h"
#include <map>


class GameObjects {
public:

	Object* child;
	Cursor* mouse;
	Enemy* enemy;
	Camera* cam;
	Player* player;
	Map* map;

	std::vector<Enemy*> enemyes;
	std::map<int, Object*> Objects;
	std::vector<Texture*> textures;

	GameObjects();
	~GameObjects();


	bool Init(Vector2d mapSize = Vector2d(2000,2000), int numEnemies = 7, int numBullets = 10);

	void Close();

	bool Tick();

	bool LateTick();

	void draw();

	void createEnemyes(int num);

	void reset();

};
#endif


