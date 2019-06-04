#ifndef CURSOR_H
#define CURSOR_H

#include "inc.h"

class Cursor  : public Object {
	Player* player;

	Gun* rgun;

public:

	Cursor(Vector2d vec = Vector2d(-15000.0f, -15000.0f), Texture* textr = TextureManager::getTexture("Scope1.png") , Type type = tUndefined, int numAmmo = 7);

	~Cursor();

	
	void setPlayer(Player* player);

	void Update(Object * obj = nullptr);

	virtual void Draw();

	Gun* getGun();

	 void onMouseMove(int x, int y, int xrelative, int yrelative);

	 void onMouseButtonClick(FRMouseButton button, bool isReleased);
	 void collisionDetected(Object* obj);
};

#endif // !CURSOR_H