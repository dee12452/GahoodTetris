#ifndef ANIMATOR_HELPER_HPP
#define ANIMATOR_HELPER_HPP

#include "BaseDrawable.hpp"
class Timer;
class Sprite;

class AnimatorHelper : public BaseDrawable {
private:
	AnimatorHelper();
	~AnimatorHelper();
	static AnimatorHelper *helper;
	bool animating;
	bool continueAnimating;
	bool parseLine(const std::string &);
	std::thread thread;
	std::string currentAnimationFile;
	void beginAnimation();
	int determineTimer(int, int);
	
	enum AnimationType {
		MOVE,
		ROTATE
	};
	
	typedef struct Animation {
		int startX;
		int startY;
		int offsetX;
		int offsetY;
		int targetX;
		int targetY;
		int timeStart;
		int duration;
		bool done;
		AnimationType type;
		Sprite *sprite;
		Timer *timerX;
		Timer *timerY;
	} Animation;

	std::vector<Animation *> animations;

public:
	static AnimatorHelper * getInstance();
	static void deleteInstance();

	void startAnimation(const std::string &);
	void stopAnimation();
	void draw(SDL_Renderer *);
};

#endif