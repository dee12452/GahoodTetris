#include "Timer.hpp"

//Use this unless you expect an FPS timer
//Declare the float explicitely, otherwise
//It'll call the next constructor
Timer::Timer(float t) {
	target = t;
	reset();
}

//Essentially an FPS timer
Timer::Timer(int t) : Timer((float) 1 / t) {}

Timer::~Timer() {}

void Timer::setTargetTime(float t) {
	target = t;
}

void Timer::setTargetTimeFPS(int t) {
	setTargetTime((float)1 / t);
}

void Timer::reset() {
	start = clock();
	finish = clock();
}

bool Timer::check() {
	finish = clock();
	if (getElapsedTime() >= target) {
		reset();
		return true;
	}
	else {
		return false;
	}
}

float Timer::getElapsedTime() {
	return (float) ((float)finish - start) / CLOCKS_PER_SEC;
}