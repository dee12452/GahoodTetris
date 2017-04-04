#ifndef BASE_MENU_HPP
#define BASE_MENU_HPP

#include "BaseInputHandler.hpp"
#include "BaseDrawable.hpp"

class BaseMenu : public BaseInputHandler, public BaseDrawable {
public:
	BaseMenu(Game *, SDL_Renderer *, const char *, const char *);
	BaseMenu(Game *, SDL_Renderer *, const char *, const char *, int, int, int, int, int, int, int, int);
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
	virtual int getNumberOfSelections() = 0;

	void draw(SDL_Renderer *);

protected:
	virtual void onLeftPressed() = 0;
	virtual void onRightPressed() = 0;
	virtual void onUpPressed() = 0;
	virtual void onDownPressed() = 0;
	virtual void onSelectMenuOption(int) = 0;

	void onKeyDown(SDL_Scancode);
	void onKeyHeld(SDL_Scancode);
	void onKeyUp(SDL_Scancode);
	void onQuitGame();

private:
	SDL_Texture *menuSprite;
	SDL_Texture *selectorSprite;
	SDL_Rect menuDestinationRect;
	SDL_Rect selectorDestinationRect;
	SDL_Rect *menuSourceRect;
	SDL_Rect *selectorSourceRect;
	
	int currentSelection;
	void onEnterPressed();
	void onEscapePressed();
};

#endif