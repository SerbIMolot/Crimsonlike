#ifndef TIMER_H
#define TIMER_H

#include "inc.h"

class Timer {
	
	static Timer* tInstance;

	unsigned int startTick;
	unsigned int elapsedTicks;
	
	float deltaTime;
	float timeScale;




public:

	Timer();
	~Timer();

	static Timer* Instance();
	static void Release();

	void Reset();
	float DeltaTime();

	void TimeScale(float t);
	float TimeScale();

	unsigned int ElapsTicks();

	void Update();

};

#endif
