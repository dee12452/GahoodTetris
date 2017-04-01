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
	Sprite(SDL_Renderer *, const char *, int, int, int, int, int);
	Sprite(SDL_Renderer *, const char *, bool, int);
	virtual ~Sprite();

	void update();
	virtual void draw(SDL_Renderer *);

	int getLocationX() const;
	int getLocationY() const;
	int getWidth() const;
	int getHeight() const;
	SDL_Texture * getTexture() const;
	bool isUsingWholeTexture() const;

	void setLocationX(int);
	void setLocationY(int);
	void setWidth(int);
	void setHeight(int);
	void setUsingWholeTexture(bool);
	void setRGBColor(Uint8, Uint8, Uint8);
	void setAlpha(Uint8);

	static const int DEFAULT_TICKS_PER_SECOND;

protected:
	SDL_Rect spriteSourceRect;
	virtual void onUpdate() = 0;

private:
	int locationX = 0;
	int locationY = 0;
	int width = 0;
	int height = 0;
	bool usingWholeTexture;
	Timer *onTickTimer;
	SDL_Texture *spriteSheet;
};

#endif
