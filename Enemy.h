#ifndef ENEMY_H
#define ENEMY_H


#include "inc.h"

class Enemy : public Object {
	Player* player;

	Vector2d moveBounds;
	Vector2d vel;

	Timer* timer;
	float enTimer;
	float moveSpeed;
public:

	Enemy(Vector2d vec = Vector2d(), Texture* textr = TextureManager::getTexture("en1.png"), Type type = tEnemy);
	~Enemy();

	void moveToPlayer();

	void spawnPoint();

	void Update(Object* obj = nullptr);

	void collisionDetected(Object * obj);
	void collisionDetected(Camera * cam);
};

#endif // !ENEMY_H