#include "../headers/BaseAnimation.hpp"
#include "../headers/Timer.hpp"

BaseAnimation::BaseAnimation(int delayMs) {
	timerDelay = new Timer(delayMs, false);
	canAnimate = false;
}

BaseAnimation::~BaseAnimation() {
	if (timerDelay != NULL) {
		delete timerDelay;
		timerDelay = NULL;
	}
}

void BaseAnimation::animate() {
	if (timerDelay != NULL && timerDelay->check()) {
		canAnimate = true;
		Timer *temp = timerDelay;
		timerDelay = NULL;
		delete temp;
		temp = NULL;
	}
	if (canAnimate) {
		onAnimate();
	}
}
