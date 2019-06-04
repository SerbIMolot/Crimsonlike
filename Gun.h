#ifndef  GUN_H
#define GUN_H

#include "inc.h"

class Gun {
	int numOfB;
	int shotsLeft;
	std::vector<Bullet*> bullets;
public:
	Gun(int numOfB);
	~Gun();

	void Init();

	std::vector<Bullet*>& getBullets();

	void Update();
	void Draw();

	int getShotsLeft();
	void reload();
	void shoot(Vector2d& player, Vector2d& target);
};

#endif // ! GUN_H

