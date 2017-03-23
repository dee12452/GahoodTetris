#include "Game.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"

Game::Game() {
	SDL_Init(SDL_INIT_VIDEO);
	window = new Window();
	handler = new InputHandler();
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

void Game::run() {
	while (window->isRendering()) {
		//std::cout << "Game here" << std::endl;
	}
}



