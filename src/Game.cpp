#include "Game.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"

Game::Game() {
	SDL_Init(SDL_INIT_VIDEO);
	window = new Window();
	handler = new InputHandler(this);
	gameState = PLAY;
    window->setOnInputHandler(handler);
	window->start();
}

Game::~Game() {
	if (window != NULL) {
		delete window;
		window = NULL;
	}
	if (handler != NULL) {
		delete handler;
		handler = NULL;
	}
	SDL_Quit();
}

Game::GameState Game::getGameState() {
    return gameState;
}

void Game::setGameState(GameState state) {
    gameState = state;
}

void Game::run() {
	while (window->isRendering()) {
		//std::cout << "Game here" << std::endl;
	}
}



