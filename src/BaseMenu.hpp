#ifndef BASE_MENU_HPP
#define BASE_MENU_HPP

#include "BaseDrawable.hpp"

class BaseMenu : public BaseDrawable {
public:
	BaseMenu(SDL_Renderer *, const char *, const char *);
	BaseMenu(SDL_Renderer *, const char *, const char *, int, int, int, int, int, int, int, int);
	virtual ~BaseMenu();

	void setMenuX(int);
	void setMenuY(int);
	void setMenuWidth(int);
	void setMenuHeight(int);
	void setSelectorX(int);
	void setSelectorY(int);
	void setSelectorWidth(int);
	void setSelectorHeight(int);
	void setCurrentSelection(int);

	int getMenuX() const;
	int getMenuY() const;
	int getMenuWidth() const;
	int getMenuHeight() const;
	int getSelectorX() const;
	int getSelectorY() const;
	int getSelectorWidth() const;
	int getSelectorHeight() const;
	int getCurrentSelection() const;

	void draw(SDL_Renderer *);

protected:
	virtual void onSetCurrentSelection() = 0;

private:
	SDL_Texture *menuSprite;
	SDL_Texture *selectorSprite;
	SDL_Rect menuDestinationRect;
	SDL_Rect selectorDestinationRect;
	SDL_Rect *menuSourceRect;
	SDL_Rect *selectorSourceRect;
	
	int currentSelection;
};

#endif