#ifndef PLAYER_H
#define PLAYER_H


#include "inc.h"

class Player : public Object {
	Timer* timer;
	long long int plTimer;

	Vector2d moveBounds;
	Vector2d vel;
	

	int moveSpeed;

	FRKey key;
	FRMouseButton mouseButton;

	static Player* pInstance;

	Player();
	Player(Vector2d vec, Texture * textr, Type type);
	~Player();
public:

	static Player* Instance();
	void Init();
	static void Close();

	void Update(Object* obj = nullptr);
	void collisionDetected(Object * obj);


	bool outOfBounds();
	
	void onKeyPressed(FRKey k);
	void onKeyReleased(FRKey k);
};

#endif // !PLAYER_H