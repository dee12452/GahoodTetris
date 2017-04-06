#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Sprite;

class MainMenu : public BaseDrawable {
public:
	MainMenu(SDL_Renderer *);
	~MainMenu();

	void draw(SDL_Renderer *);

	void nextSelection();
	void previousSelection();
	GameState selectItem() const;

private:
	Sprite *menuBG;
	Sprite *playButton;
	Sprite *exitButton;
	Sprite *selector;

	static const int BUTTON_Y;
	static const int BUTTON_WIDTH;
	static const int BUTTON_HEIGHT;

	bool shouldExit;
};

#endif 