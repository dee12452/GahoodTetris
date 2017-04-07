#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Sprite;

class MainMenu : public BaseDrawable {
public:
	MainMenu();
	~MainMenu();

	void draw(SDL_Renderer *);
	void update();

	void nextSelection();
	void previousSelection();
	GameState selectItem() const;

private:

	static const int BUTTON_Y;
	static const int BUTTON_X;
	static const int BUTTON_WIDTH;
	static const int BUTTON_HEIGHT;
	int selectorLocationX;

	bool shouldExit;
	bool selectorMoveLeft;

	void moveSelectorOnUpdate();
};

#endif 