#include "../headers/Timer.hpp"

Timer::Timer(int targetTime, bool isFPS) {
	init(targetTime, isFPS);
}

Timer::~Timer() {

}

void Timer::reset() {
	start = SDL_GetTicks();
	finish = SDL_GetTicks();
}

bool Timer::check() {
	finish = SDL_GetTicks();
	if (finish - start < 0) {
		start = 0;
	}
	if (finish - start >= targetMilliseconds) {
		reset();
		return true;
	}
	return false;
}

int Timer::getTargetMilliseconds() const { return targetMilliseconds; }
void Timer::setTargetMilliseconds(int targetTime, bool isFPS) {
	init(targetTime, isFPS);
}

void Timer::init(int targetTime, bool isFPS) {
	if (isFPS) {
		float fpms = (float)targetTime / 1000;
		fpms = 1.0f / fpms;
		targetMilliseconds = (int)fpms;
	}
	else {
		targetMilliseconds = targetTime;
	}
	reset();
}