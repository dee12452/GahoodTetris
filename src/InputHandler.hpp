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
	void onKeyDown(SDL_Scancode);
	void onKeyHeld(SDL_Scancode);
	void onKeyUp(SDL_Scancode);
	void onQuitGame();
	Game *game;
};

#endif
