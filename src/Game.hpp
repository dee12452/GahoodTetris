#ifndef GAME_HPP
#define GAME_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Window;
class InputHandler;

class Game {
public:
	Game();
	~Game();

	void run();
    GameState getGameState() const;
    void setGameState(GameState);
	BaseDrawable * getTetrisGrid() const;
	void createTetrisGrid(SDL_Renderer *);
	BaseDrawable * getPlayer() const;

private:
	Window *window;
	InputHandler *handler;
	BaseDrawable *grid;
	BaseDrawable *player;
    GameState gameState;
	int getGridX() const;
};

#endif
