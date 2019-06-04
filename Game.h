#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <thread>
#include "inc.h"

#define FPS_INTERVAL 1.0 //seconds.




	
class Game : public Framework {
	const Vector2d* windowSize;
	const Vector2d* mapSize;
	int numEnemies;
	int numAmmo;

	GameObjects* gameObj;
	TextureManager* textrMan;
	Timer* timer;
	Timer fpsTimer;

	int countedFrames = 0;


	int fps_lasttime = getTickCount(); //the last recorded time.
	int fps_current; //the current FPS.
	int fps_frames = 0; //frames passed since the last recorded fps.

public:

	Game(std::string window, std::string mapSize, int numEnemies, int numAmmo);
	~Game();

	virtual void PreInit(int& width, int& height, bool& fullscreen);

	virtual bool Init();

	virtual void Close();

	virtual bool Tick();

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

	virtual void onKeyPressed(FRKey k);

	virtual void onKeyReleased(FRKey k);

};
#endif