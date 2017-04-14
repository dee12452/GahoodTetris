#ifndef BASE_ANIMATION_HPP
#define BASE_ANIMATION_HPP

#include "Util.hpp"

class Timer;

class BaseAnimation {
public:
	BaseAnimation(int);
	virtual ~BaseAnimation();
	void animate();
	virtual void parseAnimation(const std::string &) = 0;

protected:
	virtual void onAnimate() = 0;

private:
	//Used for a delay of when the animation starts
	Timer *timerDelay;

	//If the delay timer allows, the animation can now animatee
	bool canAnimate;
};

#endif