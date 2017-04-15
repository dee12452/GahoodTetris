#ifndef BASE_ANIMATION_HPP
#define BASE_ANIMATION_HPP

#include "Util.hpp"

class Timer;

class BaseAnimation {
public:
	BaseAnimation(int);
	virtual ~BaseAnimation();
	void animate(SDL_Renderer *);
	void update();
	bool isUpdating() const;
	virtual bool isAnimating() const = 0;

protected:
	virtual void onAnimate(SDL_Renderer *) = 0;
	virtual void onUpdate() = 0;
	virtual void parseAnimation(const std::string &) = 0;
	void reset();

private:
	//Used for a delay of when the animation starts
	Timer *timerDelay;

	//If the delay timer allows, the animation can now animatee
	bool canUpdate;
};

#endif