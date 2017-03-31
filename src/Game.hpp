#ifndef GAME_HPP
#define GAME_HPP

#include "Util.hpp"

class Window;
class InputHandler;
class TetrisGrid;
class Player;

class Game {
public:
	Game();
	~Game();

	void run();
    GameState getGameState() const;
    void setGameState(GameState);
	TetrisGrid * getTetrisGrid() const;
	void createTetrisGrid(SDL_Renderer *);
	Player * getPlayer() const;

private:
	Window *window;
	InputHandler *handler;
	TetrisGrid *grid;
	Player *player;
    GameState gameState;
	int getGridX() const;
};

#endif
