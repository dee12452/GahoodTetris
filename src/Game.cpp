#include "Game.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"
#include "TetrisGrid.hpp"
#include "Player.hpp"

Game::Game() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Util::fatalSDLError("Failed to initialize SDL");
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		Util::fatalSDLError("Failed to init sdl img library");
	}
	gameState = PLAY;
    grid = NULL;
	player = new Player();
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
	if (grid != NULL) {
		delete grid;
		grid = NULL;
	}
	if (player != NULL) {
		delete player;
		player = NULL;
	}
	IMG_Quit();
	SDL_Quit();
}

GameState Game::getGameState() const {
    return gameState;
}

void Game::setGameState(GameState state) {
    gameState = state;
}

void Game::run() {
	while (window->isRendering()) {
		//perform logic here
		//SDL_Delay for the CPU usage issue
		if (grid != NULL) {
			switch (grid->update()) {
			case PLAY:
				break;
			case EXIT:
				gameState = EXIT;
				break;
			}
		}
        SDL_Delay(CPU_USAGE_LOGIC_DELAY);
	}
}

void Game::createTetrisGrid(SDL_Renderer *renderer) {
	grid = new TetrisGrid(renderer,
		getGridX(),
		0,
		DESIRED_WINDOW_HEIGHT / 2,
		DESIRED_WINDOW_HEIGHT);
}

TetrisGrid * Game::getTetrisGrid() const {
	return grid;
}

int Game::getGridX() const {
	return ((2 * DESIRED_WINDOW_WIDTH) - DESIRED_WINDOW_HEIGHT) / 4;
}

Player * Game::getPlayer() const {
	return player;
}


