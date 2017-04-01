#ifndef BASE_DRAWABLE_HPP
#define BASE_DRAWABLE_HPP

#include "Util.hpp"

class BaseDrawable {
public:
	BaseDrawable() {}
	virtual ~BaseDrawable() {}

	virtual void draw(SDL_Renderer *) = 0;
};

#endif