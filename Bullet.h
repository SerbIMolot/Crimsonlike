#ifndef BULLET_H
#define BULLET_H

#include "inc.h"

class Bullet : public Object{
	Timer* timer;
	float bulTimer;


	Vector2d* moveBounds;

	Vector2d vel;


	Rect* box;
public:
	Bullet(float x = -50000, float y = -50000, Texture* textr = TextureManager::getTexture("bullet.png"), Type type = tBullet);
	~Bullet();

	void Init();

	bool isShot();

	bool isShow();

	Rect* getBox();



	void Update(Object * obj = nullptr);

	void collisionDetected(Object * obj);
	virtual void Draw();
	void shoot(Vector2d & player, Vector2d & target);

};



#endif