#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "Const.hpp"
#include "BaseInputHandler.hpp"

class InputHandler : public BaseInputHandler {
public:
	InputHandler(Game *);
	~InputHandler() {}

protected:
	void onKeyDown(SDL_Scancode);
	void onKeyHeld(SDL_Scancode);
	void onKeyUp(SDL_Scancode);
	void onQuitGame();
};

#endif
