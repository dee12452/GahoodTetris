#include "../headers/PlayInputHandler.hpp"
#include "../headers/TetrisGrid.hpp"
#include "../headers/TetrisPiece.hpp"
#include "../headers/Player.hpp"
#include "../headers/AndroidUtil.hpp"
#include "../headers/Timer.hpp"
#include "../headers/DisplayUtil.hpp"
#include <algorithm>

PlayInputHandler::PlayInputHandler(Game *g) : BaseInputHandler(g) {
	tetrisGrid = new TetrisGrid(((2 * DESIRED_WINDOW_WIDTH) - DESIRED_WINDOW_HEIGHT) / 4, 0);
    touchTimer = new Timer(TOUCH_TIMER_TIME, false);
}

PlayInputHandler::~PlayInputHandler() {
	if (tetrisGrid != NULL) {
		delete tetrisGrid;
		tetrisGrid = NULL;
	}
    if(touchTimer != NULL) {
        delete touchTimer;
        touchTimer = NULL;
    }
}

void PlayInputHandler::onDraw(SDL_Renderer *renderer) {
    tetrisGrid->draw(renderer);
	getGame()->getPlayer()->draw(renderer);
}

void PlayInputHandler::onUpdate() {
	Player *player = static_cast<Player *> (getGame()->getPlayer());
	GameState state = getGame()->getGameState();
    static_cast<TetrisGrid *> (tetrisGrid)->update(player, state);
	if (state != getGame()->getGameState()) {
		player->resetPoints();
		getGame()->setGameState(state);
	}
	player = NULL;
}

void PlayInputHandler::onReset() {}

void PlayInputHandler::onTouch(const SDL_TouchFingerEvent &) {
    swiped = false;
    touchTimer->reset();
}

void PlayInputHandler::onTouchUp(const SDL_TouchFingerEvent &) {
    if(!swiped && !touchTimer->check()) {
        TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);
        if(grid != NULL && grid->getCurrentPiece() != NULL) {
            grid->getCurrentPiece()->rotate(grid->getGrid(), true);
        }
    }
}

void PlayInputHandler::onFingerMotion(const SDL_TouchFingerEvent &e) { 
    TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);
    if(grid == NULL || grid->getCurrentPiece() == NULL || swiped)
        return;
    int swipeX = e.dx * DisplayUtil::getScreenWidth();
    int swipeY = e.dy * DisplayUtil::getScreenHeight();
    if(std::abs(swipeX) > SWIPE_THRESHOLD && std::abs(swipeX) > std::abs(swipeY)) {
        //Swiped right
        if(swipeX > 0) {
            grid->getCurrentPiece()->moveRight(grid->getGrid());
        }
        //Swiped left
        else {
            grid->getCurrentPiece()->moveLeft(grid->getGrid());
        }
        swiped = true;
    }
    else if(std::abs(swipeY) > SWIPE_THRESHOLD) {
        //Swiped down
        if(swipeY > 0) {
            grid->placePiece();
            swiped = true;
        }
    }
    else if(touchTimer->check() && !swiped) {
        touchTimer->reset();
        grid->getCurrentPiece()->moveDown(grid->getGrid());
    }
}

void PlayInputHandler::onBackPressed() { getGame()->setGameState(MAIN_MENU); }

void PlayInputHandler::onPause() {}

void PlayInputHandler::onResume() { onBackPressed(); }

void PlayInputHandler::onDestroy() {}
