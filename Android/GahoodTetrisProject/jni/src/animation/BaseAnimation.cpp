#include "../headers/BaseAnimation.hpp"
#include "../headers/Timer.hpp"

BaseAnimation::BaseAnimation(int delayMs) {
	timerDelay = new Timer(delayMs, false);
	canUpdate = false;
}

BaseAnimation::~BaseAnimation() {
	if (timerDelay != NULL) {
		delete timerDelay;
		timerDelay = NULL;
	}
}

//Drawing
void BaseAnimation::animate(SDL_Renderer *renderer) {
	onAnimate(renderer);
}

//Updating
void BaseAnimation::update() {
	if (timerDelay->check()) {
		canUpdate = true;
	}
	if (canUpdate) {
		onUpdate();
	}
}

//Can start animating
bool BaseAnimation::isUpdating() const {
	return canUpdate;
}

void BaseAnimation::reset() {
	timerDelay->reset();
	canUpdate = false;
}
