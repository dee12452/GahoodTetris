#ifndef TIMER_HPP
#define TIMER_HPP

#include <time.h>

class Timer {
public:
	explicit Timer(float);
	Timer(int);
	~Timer();

	void reset();
	bool check();
	void setTargetTime(float);
	void setTargetTimeFPS(int);

private:
	float getElapsedTime();

	float target;
	clock_t start;
	clock_t finish;
};

#endif
