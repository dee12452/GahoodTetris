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
    swiped = false;
    moveLeft = false;
    moveRight = false;
    moveDown = false;
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
	TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);
    GameState state = getGame()->getGameState();
    if(grid != NULL && grid->getCurrentPiece() != NULL) {
        grid->update(player, state);
        if(touchTimer->check()) {
            if(moveLeft) {
                grid->getCurrentPiece()->moveLeft(grid->getGrid());
            }
            else if(moveRight) {
                grid->getCurrentPiece()->moveRight(grid->getGrid());
            }
            else if(moveDown) {
                grid->getCurrentPiece()->moveDown(grid->getGrid());
            }
        }
    }
    if (state != getGame()->getGameState()) {
		player->resetPoints();
		getGame()->setGameState(state);
	}
    grid = NULL;
	player = NULL;
}

void PlayInputHandler::onReset() {}

void PlayInputHandler::onTouch(const SDL_TouchFingerEvent &e) {
    swiped = false;
    touchTimer->reset();
    TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);
    int touchX = e.x * DisplayUtil::getScreenWidth();
    int touchY = e.y * DisplayUtil::getScreenHeight();
    Sprite *leftInd = SpriteUtil::getSprite(SpriteUtil::SPRITE_INDICATOR_LEFT);
    Sprite *rightInd = SpriteUtil::getSprite(SpriteUtil::SPRITE_INDICATOR_RIGHT);
    SDL_Rect borderRect = AndroidUtil::getSpriteTouchRect(SpriteUtil::getSprite(SpriteUtil::SPRITE_GRID_BORDER));
    if(grid != NULL && grid->getCurrentPiece() != NULL) {
        if(AndroidUtil::didTouchSprite(leftInd, touchX, touchY)) {
            moveLeft = true;
            grid->getCurrentPiece()->moveLeft(grid->getGrid());
        }
        else if(AndroidUtil::didTouchSprite(rightInd, touchX, touchY)) {
            moveRight = true;
            grid->getCurrentPiece()->moveRight(grid->getGrid());
        }
        else if(touchY > borderRect.h + borderRect.y) {
            moveDown = true;
            grid->getCurrentPiece()->moveDown(grid->getGrid());
        }
        leftInd = NULL;
        rightInd = NULL;
    }
}

void PlayInputHandler::onTouchUp(const SDL_TouchFingerEvent &e) {
    moveLeft = false;
    moveRight = false;
    moveDown = false;
    if(!swiped && !touchTimer->check()) {
        TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);
        int touchX = e.x * DisplayUtil::getScreenWidth();
        int touchY = e.y * DisplayUtil::getScreenHeight();
        if(grid != NULL && grid->getCurrentPiece() != NULL) {
            if(AndroidUtil::didTouchSprite(SpriteUtil::getSprite(SpriteUtil::SPRITE_GRID_BORDER), touchX, touchY)) {
                grid->getCurrentPiece()->rotate(grid->getGrid(), true);
            }
        }
    }
}

void PlayInputHandler::onFingerMotion(const SDL_TouchFingerEvent &e) { 
    TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);
    if(grid == NULL || grid->getCurrentPiece() == NULL || swiped || moveLeft || moveRight || moveDown)
        return;
    int swipeY = e.dy * DisplayUtil::getScreenHeight();
    if(std::abs(swipeY) > SWIPE_THRESHOLD) {
        //Swiped down
        if(swipeY > 0) {
            grid->placePiece();
            swiped = true;
        }
    }
}

void PlayInputHandler::onBackPressed() { 
    getGame()->setGameState(MAIN_MENU);
    static_cast<Player *> (getGame()->getPlayer())->resetPoints();
}

void PlayInputHandler::onPause() {}

void PlayInputHandler::onResume() { onBackPressed(); }

void PlayInputHandler::onDestroy() {}
