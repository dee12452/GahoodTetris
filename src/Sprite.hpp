#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Util.hpp"

class Timer;

class Sprite {
public:
	//Window renderer
	//Sprite sheet file name,
	//Sprite sheet x location
	//Sprite sheet y location
	//Sprite sheet width of target texture area
	//Sprite sheet height of target texture area
	//ticks per second
	Sprite(SDL_Renderer *, const char *, int, int, int, int, int);
	virtual ~Sprite();

	void update();
	virtual void draw(SDL_Renderer *, SDL_Texture *);

	int getLocationX() const;
	int getLocationY() const;
	int getWidth() const;
	int getHeight() const;
	SDL_Texture * getTexture() const;

	void setLocationX(int);
	void setLocationY(int);
	void setWidth(int);
	void setHeight(int);

	static const int DEFAULT_TICKS_PER_SECOND;

protected:
	SDL_Rect spriteSourceRect;
	virtual void onUpdate() = 0;

private:
	int locationX;
	int locationY;
	int width;
	int height;
	Timer *onTickTimer;
	SDL_Texture *spriteSheet;
};

#endif