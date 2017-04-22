#ifndef GAME_HPP
#define GAME_HPP

#include "Util.hpp"

class Window;
class BaseInputHandler;
class BaseDrawable;

class Game {
public:
	Game();
	~Game();

	void run();
    GameState getGameState() const;
	BaseDrawable * getPlayer() const;
    void setGameState(GameState);

private:
	Window *window;
	BaseInputHandler *currentHandler;
	BaseDrawable *player;
    GameState gameState;

	void changeEventHandler();
	bool stateChanged;
};

#endif
