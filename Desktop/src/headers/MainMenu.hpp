#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Sprite;

class MainMenu : public BaseDrawable {
public:
	MainMenu();
	~MainMenu();

	void draw(SDL_Renderer *) override;
	void update();

	void nextSelection();
	void previousSelection();
    void verticalSelection();
	GameState selectItem() const;

private:
	static const int BUTTON_Y;
	static const int BUTTON_X;
	static const int BUTTON_WIDTH;
	static const int BUTTON_HEIGHT;
	int selectorLocationX;

	bool shouldExit, shouldHelp;
	bool selectorMoveLeft;

	void moveSelectorOnUpdate();

	Sprite *blockRed,
		*blockYellow,
		*blockBlue,
		*blockPurple,
		*blockOrange,
		*blockGrey;
};

#endif 
