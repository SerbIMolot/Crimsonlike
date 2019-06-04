#ifndef CAMERA_H
#define CAMERA_H
#include "inc.h"

class Camera {
	static Camera* cInstance;

	Vector2d* pos;
	
	int mapX, mapY;
	int screenW, screenH;
	
	Rect* box;
	
	Player* player;
	
	Type type;
	
	Camera(int mapX, int mapY, Player* player);
	Camera();
	~Camera();
public:

	void Init();
	void setMap();
	static Camera* Instance();

	static void Release();

	void setPlayer(Player * player);

	Rect* getBox();
	Type* getType();

	Vector2d& Pos();

	void updateBox();

	void Update();

};

#endif