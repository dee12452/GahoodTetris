#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "BaseInputHandler.hpp"

class InputHandler : public BaseInputHandler {
public:
	InputHandler();
	~InputHandler();

protected:
	void onKeyDown();
	void onKeyHeld(SDL_Scancode);
	void onKeyUp();
	void onQuitGame();
};

#endif 