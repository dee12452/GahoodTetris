#ifndef ANIMATOR_HELPER_HPP
#define ANIMATOR_HELPER_HPP

#include "BaseDrawable.hpp"
#include "AndroidUtil.hpp"

class BaseAnimation;

class AnimatorHelper : public BaseDrawable {
private:
	AnimatorHelper();
	~AnimatorHelper();
	pthread_t animationThread;
	bool animating, updating;
	static AnimatorHelper *helper;
	std::vector<BaseAnimation *> animations;
	void parseAnimationFile(const std::string &);

public:
	static AnimatorHelper * getInstance();
	static std::string createClearAnimation(int, int, int);
    static void deleteInstance();

	void draw(SDL_Renderer *) override;
	void startAnimation(const std::string &);
	void pauseAnimation();
	void resumeAnimation();
    void stopAnimation();
    void animate();

	bool isAnimating() const;
    bool getAnimating() const;
    std::vector<BaseAnimation *> getAnimationsToAnimate() const;
};

#endif
