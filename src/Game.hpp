#ifndef GAME_HPP
#define GAME_HPP

#include "Const.hpp"

class Window;
class InputHandler;

class Game {
public:
	Game();
	~Game();

	void run();

private:
	Window *window;
	InputHandler *handler;
};

#endif