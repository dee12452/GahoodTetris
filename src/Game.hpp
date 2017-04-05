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

	void createGameDrawables(SDL_Renderer *);
	std::vector<std::vector<BaseDrawable *>> getGameDrawables() const;
	std::vector<BaseInputHandler *> getInputHandlers() const;

private:
	Window *window;
    GameState gameState;

	void createInputHandlers();
	std::vector<std::vector<BaseDrawable *>> gameDrawables;
	std::vector<BaseInputHandler *> inputHandlers;
};

#endif
