#include "../headers/Game.hpp"
#include "../headers/Window.hpp"
#include "../headers/Player.hpp"
#include "../headers/PlayInputHandler.hpp"
#include "../headers/MenuInputHandler.hpp"
#include "../headers/AnimatorHelper.hpp"

Game::Game() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Util::fatalSDLError("Failed to initialize SDL");
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		Util::fatalSDLError("Failed to init sdl img library");
	}
	player = new Player();
	window = new Window();
	currentHandler = NULL;
	stateChanged = false;
}

Game::~Game() {
	if (window != NULL) {
		delete window;
		window = NULL;
	}
	if (currentHandler != NULL) {
		delete currentHandler;
		currentHandler = NULL;
	}
	if (player != NULL) {
		delete player;
		player = NULL;
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
		stateChanged = true;
	}
}

void Game::run() {
	window->start();
	setGameState(MAIN_MENU);
	while (window->isRendering()) {
		SDL_Delay(CPU_USAGE_LOGIC_DELAY);

		if(currentHandler != NULL)
			currentHandler->onUpdate();

		if (stateChanged) {
			changeEventHandler();
		}

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

void Game::changeEventHandler() {
	BaseInputHandler *temp = NULL;
	switch (gameState) {
	case PLAY:
		temp = currentHandler;
		currentHandler = new PlayInputHandler(this);
		window->setInputHandler(currentHandler);
		if (temp != NULL) {
			delete temp;
			temp = NULL;
		}
		window->releaseHandlerLock();
		break;
	case MAIN_MENU:
		temp = currentHandler;
		currentHandler = new MenuInputHandler(this);
		window->setInputHandler(currentHandler);
		if (temp != NULL) {
			delete temp;
			temp = NULL;
		}
		window->releaseHandlerLock();
		break;
	default:
		break;
	}	
	stateChanged = false;
}

BaseDrawable * Game::getPlayer() const {
	return player;
}