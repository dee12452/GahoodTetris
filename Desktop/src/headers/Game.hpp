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

	void changeEventHandler();
    void startWindow() const;
    bool getWindowState() const;
    bool shouldChangeState() const;
    BaseInputHandler * getCurrentHandler() const;
    GameState getGameState() const;
	BaseDrawable * getPlayer() const;
    void setGameState(GameState);

private:
	pthread_t thread;
    Window *window;
	BaseInputHandler *currentHandler;
	BaseDrawable *player;
    GameState gameState;

	bool stateChanged;
};

#endif
