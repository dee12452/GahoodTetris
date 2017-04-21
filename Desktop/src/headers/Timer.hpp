#ifndef TIMER_HPP
#define TIMER_HPP

#include "Util.hpp"

class Timer {
public:
	Timer(int, bool);
	~Timer();

	void reset();
	bool check();
	int getTargetMilliseconds() const;
	void setTargetMilliseconds(int, bool);

private:
	void init(int, bool);
	int targetMilliseconds;
	uint16_t start;
	uint16_t finish;
};

#endif
