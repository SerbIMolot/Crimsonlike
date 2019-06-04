#include "inc.h"


Timer* Timer::tInstance = nullptr;

Timer* Timer::Instance() {
	if (tInstance == nullptr) {
		tInstance = new Timer();
	}

	return tInstance;
}

void Timer::Release() {

	delete tInstance;
	tInstance = nullptr;

}

void Timer::Reset() {

	startTick = getTickCount();
	elapsedTicks = 0;
	deltaTime = 0.0f;

}

float Timer::DeltaTime() {
	return deltaTime;
}

void Timer::TimeScale(float t) {
	timeScale = t;
}

float Timer::TimeScale() {
	return timeScale;
}

unsigned int Timer::ElapsTicks() {
	return elapsedTicks;
}

void Timer::Update() {


	elapsedTicks = getTickCount() - startTick;
	deltaTime = (elapsedTicks * 0.001f) ;

}

Timer::Timer() {
	Reset();
	timeScale = 1.0f;
}

Timer::~Timer() {

}