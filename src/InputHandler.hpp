#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "Const.hpp"
#include "BaseInputHandler.hpp"

class Game;

class InputHandler : public BaseInputHandler {
public:
	InputHandler(Game *);
	~InputHandler() {}

	Game * getGame() const;

protected:
	void onKeyDown();
	void onKeyHeld(SDL_Scancode);
	void onKeyUp();
	void onQuitGame();
	Game *game;
};

#endif