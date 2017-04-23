#ifndef ANIMATOR_HELPER_HPP
#define ANIMATOR_HELPER_HPP

#include "BaseDrawable.hpp"
#include "AndroidUtil.hpp"

class BaseAnimation;

class AnimatorHelper : public BaseDrawable {
private:
	AnimatorHelper();
	~AnimatorHelper();
	std::thread animationThread;
	bool animating, updating;
	static AnimatorHelper *helper;
	std::vector<BaseAnimation *> animations;
	void parseAnimationFile(const std::string &);
	void animate();

public:
	static AnimatorHelper * getInstance();
	static std::string createClearAnimation(int, int, int);
    static void deleteInstance();

	void draw(SDL_Renderer *) override;
	void startAnimation(const std::string &);
	void pauseAnimation();
	void resumeAnimation();
    void stopAnimation();

	bool isAnimating() const;
};

#endif
