#ifndef MOVE_ANIMATION_HPP
#define MOVE_ANIMATION_HPP

#include "BaseAnimation.hpp"

class MoveAnimation : public BaseAnimation {
public:
	MoveAnimation(int);
	~MoveAnimation();
	void parseAnimation(const std::string &) override;

protected:
	void onAnimate() override;
};

#endif