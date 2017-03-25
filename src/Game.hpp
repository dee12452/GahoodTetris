#ifndef GAME_HPP
#define GAME_HPP

#include "Util.hpp"

class Window;
class InputHandler;
class TetrisGrid;

class Game {
public:
	Game();
	~Game();

    enum GameState { PLAY, EXIT };
	void run();
    GameState getGameState() const;
    void setGameState(GameState);
	TetrisGrid * getTetrisGrid() const;
	void createTetrisGrid(SDL_Renderer *);

private:
	Window *window;
	InputHandler *handler;
	TetrisGrid *grid;
    GameState gameState;
	int getGridX() const;
};

#endif
