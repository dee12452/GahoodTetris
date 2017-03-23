#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include "BaseInputHandler.hpp"

class Game;

class InputHandler : public BaseInputHandler {
public:
	InputHandler(Game *);
	~InputHandler();

    Game *getGame() const;

protected:
	void onKeyDown();
	void onKeyHeld(SDL_Scancode);
	void onKeyUp();
	void onQuitGame();

private:
    Game *game;
};

#endif 
