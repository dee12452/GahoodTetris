#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Timer;

class Sprite : public BaseDrawable {
public:
	//Window renderer
	//Sprite sheet file name,
	//Sprite sheet x location
	//Sprite sheet y location
	//Sprite sheet width of target texture area
	//Sprite sheet height of target texture area
	//ticks per second
	Sprite(SDL_Renderer *, const char *, int, int, int, int);
	Sprite(SDL_Renderer *, const char *, bool);
	virtual ~Sprite();

	virtual void draw(SDL_Renderer *);

	int getLocationX() const;
	int getLocationY() const;
	int getWidth() const;
	int getHeight() const;
	bool isUsingWholeTexture() const;

	void setLocationX(int);
	void setLocationY(int);
	void setWidth(int);
	void setHeight(int);
	void setUsingWholeTexture(bool);
	void setRGBColor(Uint8, Uint8, Uint8);
	void setAlpha(Uint8);	

private:
	int locationX = 0;
	int locationY = 0;
	int width = 0;
	int height = 0;
	bool usingWholeTexture;
	SDL_Texture *spriteSheet;
	SDL_Rect spriteSourceRect;
};

#endif
