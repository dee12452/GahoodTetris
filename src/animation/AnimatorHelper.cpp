#include "../headers/AnimatorHelper.hpp"
#include "../headers/BaseAnimation.hpp"
#include <fstream>

AnimatorHelper * AnimatorHelper::helper = NULL;

AnimatorHelper::AnimatorHelper() { 
	animating = false;
}

AnimatorHelper::~AnimatorHelper() {}

AnimatorHelper * AnimatorHelper::getInstance() {
	if (helper == NULL) {
		helper = new AnimatorHelper();
	}
	return helper;
}

void AnimatorHelper::deleteInstance() {
	if (helper != NULL) {
		helper->stopAnimation();
		delete helper;
		helper = NULL;
	}
}

void AnimatorHelper::draw(SDL_Renderer *renderer) {
}

void AnimatorHelper::startAnimation(const std::string &file) {
	if (!animating) {
		animating = true;
		parseAnimationFile(file);
		animationThread = std::thread(&AnimatorHelper::animate, this);
	}
}

void AnimatorHelper::stopAnimation() {
	if (animating) {
		animating = false;
		animationThread.join();
		for (size_t i = 0; i < animations.size(); i++) {
			delete animations[i];
			animations[i] = 0;
		}
		animations.clear();
	}
}

void AnimatorHelper::animate() {
	while (animating) {
		for (size_t i = 0; i < animations.size(); i++) {
			animations[i]->animate();
		}
	}
}

void AnimatorHelper::parseAnimationFile(const std::string &file) {

}

bool AnimatorHelper::isAnimating() const {
	return animating;
}
