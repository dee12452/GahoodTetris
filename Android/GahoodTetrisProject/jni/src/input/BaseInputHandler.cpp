#include "../headers/BaseInputHandler.hpp"
#include "../headers/DisplayUtil.hpp"
#include "../headers/AndroidUtil.hpp"
#include "../headers/AnimatorHelper.hpp"

BaseInputHandler::BaseInputHandler(Game *g) { this->game = g; gameCreated = false; isPaused = false; }

BaseInputHandler::~BaseInputHandler() {}

void BaseInputHandler::update() {
    if(!isPaused) {
        onUpdate();
    }
}

void BaseInputHandler::draw(SDL_Renderer *renderer) {
    if(!isPaused) {
        onDraw(renderer);
        AnimatorHelper::getInstance()->draw(renderer);
    }
}

void BaseInputHandler::pollEvents() {
    SDL_Event e;
    int screenWidth = DisplayUtil::getScreenWidth();
    int screenHeight = DisplayUtil::getScreenHeight();
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			onQuitGame();
			break;
        case SDL_APP_TERMINATING:
            onDestroy();
            break;
        case SDL_APP_DIDENTERBACKGROUND:
            isPaused = true;
            AnimatorHelper::getInstance()->pauseAnimation();
            onPause();
            break;
        case SDL_APP_DIDENTERFOREGROUND:
            isPaused = false;
            AnimatorHelper::getInstance()->resumeAnimation();
            onResume();
            break;
        case SDL_FINGERDOWN: {
            int touchX = e.tfinger.x * screenWidth;
            int touchY = e.tfinger.y * screenHeight;
            onTouch(touchX, touchY);
            break;
        }
        case SDL_FINGERUP:
            break;
        case SDL_FINGERMOTION:
            onSwipe();
            break;
        default:
			break;
		}
	}
}

Game * BaseInputHandler::getGame() const { return game; }

GameState BaseInputHandler::getCurrentGameState() const {
	return game->getGameState();
}

void BaseInputHandler::setGameState(GameState gs) const {
	game->setGameState(gs);
}

void BaseInputHandler::onQuitGame() {
	game->setGameState(EXIT);
}
