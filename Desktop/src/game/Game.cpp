#include "../headers/Game.hpp"
#include "../headers/Window.hpp"
#include "../headers/Player.hpp"
#include "../headers/PlayInputHandler.hpp"
#include "../headers/MenuInputHandler.hpp"
#include "../headers/AnimatorHelper.hpp"
#include "../headers/HowToPlayInputHandler.hpp"

void * run(void *);

Game::Game() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Util::fatalSDLError("Failed to initialize SDL");
	}
	if (IMG_Init(IMG_INIT_PNG) < 0) {
		Util::fatalSDLError("Failed to init sdl img library");
	}
	player = (BaseDrawable *) new Player();
	window = new Window();
	currentHandler = NULL;
    gameState = START;
	stateChanged = false;
    window->init();
    pthread_create(&thread, NULL, run, this);
    window->start();
}

Game::~Game() {
	if (window != NULL) {
		delete window;
		window = NULL;
	}
    pthread_join(thread, NULL);
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

bool Game::getWindowState() const {
    return window->isRendering();
}

bool Game::shouldChangeState() const {
    return stateChanged;
}

BaseInputHandler * Game::getCurrentHandler() const {
    return currentHandler;
}

void * run(void *data) {
    Game *game = (Game *) data;
	game->setGameState(MAIN_MENU);
    while (game->getWindowState()) {
        SDL_Delay(CPU_USAGE_LOGIC_DELAY);
		
		if (game->shouldChangeState()) {
			game->changeEventHandler();
		}
        
        switch (game->getGameState()) {
			case MAIN_MENU:
                if(game->getCurrentHandler() != NULL) {
                    game->getCurrentHandler()->onUpdate();
                }
				break;
			case PLAY:
                if(game->getCurrentHandler() != NULL) {
                    game->getCurrentHandler()->onUpdate();
                }
				break;
		    default:
				break;
		}
	}
    return NULL;
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
        AnimatorHelper::getInstance()->stopAnimation();
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
        AnimatorHelper::getInstance()->startAnimation(ANIMATION_MAIN_MENU);
        break;
    case HOW_TO_PLAY:
		temp = currentHandler;
		currentHandler = new HowToPlayInputHandler(this);
		window->setInputHandler(currentHandler);
		if (temp != NULL) {
			delete temp;
			temp = NULL;
		}
		window->releaseHandlerLock();
        AnimatorHelper::getInstance()->stopAnimation();
        break;
	default:
        AnimatorHelper::getInstance()->stopAnimation();
		break;
	}	
	stateChanged = false;
}

BaseDrawable * Game::getPlayer() const {
	return player;
}
