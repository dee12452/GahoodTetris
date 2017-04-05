#ifndef MENU_INPUT_HANDLER
#define MENU_INPUT_HANDLER

#include "Util.hpp"
#include "BaseInputHandler.hpp"

class MenuInputHandler : public BaseInputHandler {
public:
	MenuInputHandler(Game *);
	~MenuInputHandler();

protected:
	void onKeyDown(SDL_Scancode);
	void onKeyHeld(SDL_Scancode);
	void onKeyUp(SDL_Scancode);
};

#endif