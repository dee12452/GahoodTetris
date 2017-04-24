#include "../headers/BaseInputHandler.hpp"
#include "../headers/DisplayUtil.hpp"
#include "../headers/AndroidUtil.hpp"
#include "../headers/AnimatorHelper.hpp"
#include "../headers/Timer.hpp"
#include <algorithm>


BaseInputHandler::BaseInputHandler(Game *g) { 
    this->game = g; 
    gameCreated = false; 
    isPaused = false;
    swiped = false, isSwiping = false;
    touchTimer = new Timer(TOUCH_TIMER_TIME, false);
}

BaseInputHandler::~BaseInputHandler() {
    if(touchTimer != NULL) {
        delete touchTimer;
        touchTimer = NULL;
    }
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
    int screenWidth = DisplayUtil::getScreenWidth();
    int screenHeight = DisplayUtil::getScreenHeight();
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
        case SDL_FINGERDOWN: {
            isSwiping = false;
            swiped = false;
            touchTimer->reset();
            break;
        }
        case SDL_FINGERUP: {
            if(!swiped) {
                int touchX = e.tfinger.x * screenWidth;
                int touchY = e.tfinger.y * screenHeight;
                onTap(touchX, touchY);
            }
            break;
        }
        case SDL_FINGERMOTION:
        {
            if(swiped)
                break;
            if(touchTimer->check()) {
                isSwiping = true;
            }
            if(!isSwiping) {
                break;
            }
            float changeX = e.tfinger.dx;
            float changeY = e.tfinger.dy; 
            float swipeHorThreshold = 0.008f;
            float swipeVertThreshold = 0.001f;
            //Swiped Right
            if(changeX > 0.0f) {
                if(std::abs(changeX) > std::abs(changeY)) {
                    if(std::abs(changeX) > swipeHorThreshold)
                        onSwipe(RIGHT);
                        swiped = true;
                }

                else if(std::abs(changeY) > swipeVertThreshold) {
                    //Swiped Up
                    if(changeY > 0.0f) {
                        onSwipe(DOWN);
                        swiped = true;
                    }

                    //Swiped Down
                    else {
                        onSwipe(UP);
                        swiped = true;
                    }
                }
            }

            //Swiped Left
            else {
                if(std::abs(changeX) > std::abs(changeY)) {
                    if(std::abs(changeX) > swipeHorThreshold) {
                        onSwipe(LEFT);
                        swiped = true;
                    }
                }

                else if(std::abs(changeY) > swipeVertThreshold) {
                    //Swiped Up
                    if(changeY > 0.0f) {
                        onSwipe(DOWN);
                        swiped = true;
                    }

                    //Swiped Down
                    else {
                        onSwipe(UP);
                        swiped = true;
                    }
                }
            }
            onSwipe(NO_DIRECTION);
            break;
        }
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
