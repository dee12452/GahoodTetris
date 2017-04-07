#include "Game.hpp"
#include "Window.hpp"
#include "PlayInputHandler.hpp"
#include "MenuInputHandler.hpp"
#include "TetrisGrid.hpp"
#include "MainMenu.hpp"
#include "Player.hpp"

Game::Game() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Util::fatalSDLError("Failed to initialize SDL");
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		Util::fatalSDLError("Failed to init sdl img library");
	}
	window = new Window();
	createInputHandlers();
}

Game::~Game() {
	if (window != NULL) {
		delete window;
		window = NULL;
	}
	for (size_t i = 0; i < inputHandlers.size(); i++) {
		if (inputHandlers[i] != NULL) {
			delete inputHandlers[i];
			inputHandlers[i] = NULL;
		}
	}
	for (size_t i = 0; i < gameDrawables.size(); i++) {
		for (size_t j = 0; j < gameDrawables[i].size(); j++) {
			if (gameDrawables[i][j] != NULL) {
				delete gameDrawables[i][j];
				gameDrawables[i][j] = NULL;
			}
		}
	}
	IMG_Quit();
	SDL_Quit();
}

GameState Game::getGameState() const {
    return gameState;
}

void Game::setGameState(GameState state) {
	if (gameState != state) {
		gameState = state;
		if (state == EXIT)
			return;

		if (gameDrawables.size() != 0) {
			static_cast<TetrisGrid *> (gameDrawables[VECTOR_PLAY][VECTOR_PLAY_GRID])->reset();
			static_cast<Player *> (gameDrawables[VECTOR_PLAY][VECTOR_PLAY_PLAYER])->resetPoints();
		}
		window->setInputHandler(inputHandlers[static_cast<int> (gameState)]);
	}
}

void Game::run() {
	setGameState(MENU);
	window->start();
	while (window->isRendering()) {
		SDL_Delay(CPU_USAGE_LOGIC_DELAY);

		//perform logic here
		//SDL_Delay for the CPU usage issue
		if (gameDrawables.size() == 0) {
			SDL_Delay(CPU_USAGE_LOGIC_DELAY);
			continue;
		}

		switch (gameState) {
			case MENU:
				if (gameDrawables[VECTOR_MENU][VECTOR_MENU_MAIN] != NULL) {
					MainMenu *menu = static_cast<MainMenu *> (gameDrawables[VECTOR_MENU][VECTOR_MENU_MAIN]);
					menu->update();
				}
				break;
			case PLAY:
				if (gameDrawables[VECTOR_PLAY][VECTOR_PLAY_GRID] != NULL) {
					TetrisGrid *tGrid = static_cast<TetrisGrid *> (gameDrawables[VECTOR_PLAY][VECTOR_PLAY_GRID]);
					GameState newState;
					newState = tGrid->update(static_cast<Player *> (gameDrawables[VECTOR_PLAY][VECTOR_PLAY_PLAYER]));
					if (newState != PLAY)
						setGameState(newState);
				}
				break;
			case EXIT:
				break;
		}
	}
}

std::vector<std::vector<BaseDrawable *>> Game::getGameDrawables() const {
	return gameDrawables;
}

void Game::createGameDrawables() {
	
	//Create menu drawables
	std::vector<BaseDrawable *> menu;
	menu.push_back(new MainMenu());

	//Create play drawables
	std::vector<BaseDrawable *> play;
	play.push_back(new TetrisGrid(((2 * DESIRED_WINDOW_WIDTH) - DESIRED_WINDOW_HEIGHT) / 4,
		0));
	play.push_back(new Player());

	//Push back those game vectors
	gameDrawables.push_back(menu);
	gameDrawables.push_back(play);
}

void Game::createInputHandlers() {
	//menu input handler
	inputHandlers.push_back(new MenuInputHandler(this));

	//play input handler
	inputHandlers.push_back(new PlayInputHandler(this));
}

std::vector<BaseInputHandler *> Game::getInputHandlers() const {
	return inputHandlers;
}
