#ifndef MOVE_ANIMATION_HPP
#define MOVE_ANIMATION_HPP

#include "BaseAnimation.hpp"
#include <chrono>

class Sprite;

class MoveAnimation : public BaseAnimation {
public:
	MoveAnimation(int, const std::string &);
	~MoveAnimation();

	bool isAnimating() const override;
	
protected:
	void onAnimate(SDL_Renderer *) override;
	void onUpdate() override;
	void parseAnimation(const std::string &) override;

private:
	int spriteId;
	int startX;
	int startY;
	int offsetX;
	int offsetY;
	int finishX;
	int finishY;
	int time;
	int isInfinite;

	//Updating for the movement to get the correct time
	std::chrono::milliseconds start, finish;
	bool firstUpdate;
};

#endif