#ifndef GAME_HPP
#define GAME_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Window;
class BaseInputHandler;

class Game {
public:
	Game();
	~Game();

	void run();
    GameState getGameState() const;
    void setGameState(GameState);

private:
	Window *window;
	BaseInputHandler *currentHandler;
	BaseInputHandler *playHandler;
	BaseInputHandler *mainMenuHandler;
    GameState gameState;

	void initEventHandlers();
	void changeEventHandler();
};

#endif
