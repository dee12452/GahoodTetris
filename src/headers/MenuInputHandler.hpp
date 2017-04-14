#ifndef MENU_INPUT_HANDLER
#define MENU_INPUT_HANDLER

#include "Util.hpp"
#include "BaseInputHandler.hpp"

class MainMenu;

class MenuInputHandler : public BaseInputHandler {
public:
	MenuInputHandler(Game *);
	~MenuInputHandler();
	 
	void onDraw(SDL_Renderer *);
	void onUpdate();
	void onReset();

protected:
	void onKeyDown(SDL_Scancode);
	void onKeyHeld(SDL_Scancode);
	void onKeyUp(SDL_Scancode);

private:
	MainMenu *menu;
};

#endif