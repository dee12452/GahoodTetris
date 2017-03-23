#ifndef GAME_HPP
#define GAME_HPP

#include "Util.hpp"

class Window;
class InputHandler;

class Game {
public:
	Game();
	~Game();

    enum GameState { PLAY, EXIT };
	void run();
    GameState getGameState();
    void setGameState(GameState);

private:
	Window *window;
	InputHandler *handler;
    GameState gameState;
};

#endif
