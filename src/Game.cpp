#include "Game.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"

Game::Game() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Util::fatalSDLError("Failed to initialize SDL");
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		Util::fatalSDLError("Failed to init sdl img library");
	}
	gameState = PLAY;
	handler = new InputHandler(this);
	window = new Window(handler);
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
	IMG_Quit();
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



