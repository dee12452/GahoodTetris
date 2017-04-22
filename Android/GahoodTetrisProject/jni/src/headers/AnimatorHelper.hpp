#ifndef ANIMATOR_HELPER_HPP
#define ANIMATOR_HELPER_HPP

#include "BaseDrawable.hpp"

class BaseAnimation;

class AnimatorHelper : public BaseDrawable {
private:
	AnimatorHelper();
	~AnimatorHelper();
	std::thread animationThread;
	bool animating;
	static AnimatorHelper *helper;
	std::vector<BaseAnimation *> animations;
	void parseAnimationFile(const std::string &);
	void animate();

public:
	static AnimatorHelper * getInstance();
	static void createClearAnimationFile(int, int, int);
    static void deleteInstance();

	void draw(SDL_Renderer *) override;
	void startAnimation(const std::string &);
	void stopAnimation();

	bool isAnimating() const;
};

#endif
