How to use an animator

You need to have this include:
	#include "AnimatorHelper.hpp"

From your class, start an animation by loading the singleton and calling "startAnimation":
	AnimatorHelper::getInstance()->startAnimation(<Filename as a string>);

At anytime that you need to stop an animation, you can call
	AnimatorHelper::getInstance()->stopAnimation();

If you call startAnimation(const char *); without stopping a previous animation, it will fail,
so make sure to stop an animation before starting a new one.