#include "Game.hpp"
#include "Window.hpp"
#include "Player.hpp"
#include "PlayInputHandler.hpp"
#include "MenuInputHandler.hpp"
#include "AnimatorHelper.hpp"

Game::Game() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Util::fatalSDLError("Failed to initialize SDL");
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		Util::fatalSDLError("Failed to init sdl img library");
	}
	window = new Window();
	currentHandler = NULL;
	playHandler = NULL;
	mainMenuHandler = NULL;
}

Game::~Game() {
	if (window != NULL) {
		delete window;
		window = NULL;
	}
	currentHandler = NULL;
	if (playHandler != NULL) {
		delete playHandler;
		playHandler = NULL;
	}
	if (mainMenuHandler != NULL) {
		delete mainMenuHandler;
		mainMenuHandler = NULL;
	}
	AnimatorHelper::deleteInstance();
	IMG_Quit();
	SDL_Quit();
}

GameState Game::getGameState() const {
    return gameState;
}

void Game::setGameState(GameState state) {
	if (gameState != state) {
		gameState = state;
		changeEventHandler();
	}
}

void Game::run() {
	window->start();
	initEventHandlers();
	setGameState(MAIN_MENU);
	while (window->isRendering()) {
		SDL_Delay(CPU_USAGE_LOGIC_DELAY);

		currentHandler->onUpdate();

		switch (gameState) {
			case MAIN_MENU:
				break;
			case PLAY:
				break;
			case EXIT:
				break;
		}
	}
}

void Game::initEventHandlers() {
	playHandler = new PlayInputHandler(this);
	mainMenuHandler = new MenuInputHandler(this);
}

void Game::changeEventHandler() {
	switch (gameState) {
	case PLAY:
		currentHandler = playHandler;
		currentHandler->onReset();
		window->setInputHandler(currentHandler);
		break;
	case MAIN_MENU:
		currentHandler = mainMenuHandler;
		currentHandler->onReset();
		window->setInputHandler(currentHandler);
		break;
	default:
		break;
	}	
}
