#include "../headers/PlayInputHandler.hpp"
#include "../headers/TetrisGrid.hpp"
#include "../headers/TetrisPiece.hpp"
#include "../headers/Player.hpp"
#include "../headers/AndroidUtil.hpp"

PlayInputHandler::PlayInputHandler(Game *g) : BaseInputHandler(g) {
	tetrisGrid = new TetrisGrid(((2 * DESIRED_WINDOW_WIDTH) - DESIRED_WINDOW_HEIGHT) / 4, 0);
}

PlayInputHandler::~PlayInputHandler() {
	if (tetrisGrid != NULL) {
		delete tetrisGrid;
		tetrisGrid = NULL;
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

void PlayInputHandler::onTouch(int x, int y) {
	TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);
    if(AndroidUtil::didTouchSprite(SpriteUtil::getSprite(SpriteUtil::SPRITE_GRID_BORDER), x, y)) {
        if(grid != NULL && grid->getCurrentPiece() != NULL) {
            grid->getCurrentPiece()->rotate(grid->getGrid(), true);
        }
    }
}

void PlayInputHandler::onTouchAndHold(int, int) {}

void PlayInputHandler::onSwipe(Direction d) {
	TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);
    GameState state = getGame()->getGameState();
    switch(d) {
        case DOWN:
            if(grid == NULL || grid->getCurrentPiece() == NULL)
                break;
            grid->placePiece(static_cast<Player *>(getGame()->getPlayer()), state);
            if(state != getGame()->getGameState()) {
                static_cast<Player *> (getGame()->getPlayer())->resetPoints();
                getGame()->setGameState(state);
            }
            break;
        case LEFT:
            if(grid == NULL || grid->getCurrentPiece() == NULL)
                break;
			grid->getCurrentPiece()->moveLeft(grid->getGrid());
            break;
        case RIGHT:
            if(grid == NULL || grid->getCurrentPiece() == NULL)
                break;
			grid->getCurrentPiece()->moveRight(grid->getGrid());
            break;
        default:
            break;
    }
}

void PlayInputHandler::onBackPressed() { getGame()->setGameState(MAIN_MENU); }

void PlayInputHandler::onPause() {}

void PlayInputHandler::onResume() {}

void PlayInputHandler::onDestroy() {}

/*
void PlayInputHandler::onKeyDown(SDL_Scancode key) {
	TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);
    GameState state = getGame()->getGameState();
	switch(key) {
        case SDL_SCANCODE_LEFT:
            if(grid == NULL || grid->getCurrentPiece() == NULL)
                break;
			grid->getCurrentPiece()->moveLeft(grid->getGrid());
            break;
        case SDL_SCANCODE_RIGHT:
            if(grid == NULL || grid->getCurrentPiece() == NULL)
                break;
			grid->getCurrentPiece()->moveRight(grid->getGrid());
            break;
        case SDL_SCANCODE_DOWN:
            if(grid == NULL || grid->getCurrentPiece() == NULL)
                break;
            if(!grid->getCurrentPiece()->moveDown(grid->getGrid())) {
                grid->placePiece(static_cast<Player *>(getGame()->getPlayer()), state);
            }
            break;
		case SDL_SCANCODE_SPACE:
            if(grid == NULL || grid->getCurrentPiece() == NULL)
                break;
			grid->getCurrentPiece()->rotate(grid->getGrid(), true);
			break;
		case SDL_SCANCODE_ESCAPE:
			static_cast<Player *> (getGame()->getPlayer())->resetPoints();
			getGame()->setGameState(MAIN_MENU);
			break;
        case SDL_SCANCODE_RETURN:
            if(grid == NULL || grid->getCurrentPiece() == NULL)
                break;
            grid->placePiece(static_cast<Player *>(getGame()->getPlayer()), state);
            if(state != getGame()->getGameState()) {
                static_cast<Player *> (getGame()->getPlayer())->resetPoints();
                getGame()->setGameState(state);
            }
            break;
        default:
            break;
    }
}
*/
