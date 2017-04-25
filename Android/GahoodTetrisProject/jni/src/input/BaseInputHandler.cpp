#include "../headers/BaseInputHandler.hpp"
#include "../headers/DisplayUtil.hpp"
#include "../headers/AndroidUtil.hpp"
#include "../headers/AnimatorHelper.hpp"
#include "../headers/Timer.hpp"

BaseInputHandler::BaseInputHandler(Game *g) { 
    this->game = g; 
    gameCreated = false; 
    isPaused = false;
}

BaseInputHandler::~BaseInputHandler() {
}

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
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			onQuitGame();
			break;
        case SDL_KEYDOWN:
            if(e.key.keysym.sym == SDLK_AC_BACK)
                onBackPressed();
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
        case SDL_FINGERDOWN:
            onTouch(e.tfinger);
            break;
        case SDL_FINGERUP:
            onTouchUp(e.tfinger);
            break;
        case SDL_FINGERMOTION:
            onFingerMotion(e.tfinger);
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
