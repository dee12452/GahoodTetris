#include "PlayInputHandler.hpp"
#include "TetrisGrid.hpp"
#include "TetrisPiece.hpp"

PlayInputHandler::PlayInputHandler(Game *g) : BaseInputHandler(g) {
}

void PlayInputHandler::onKeyDown(SDL_Scancode key) {
	TetrisGrid *tGrid;
    switch(key) {
        case SDL_SCANCODE_LEFT:
			if (getCurrentGameDrawables().size() != 0) {
				tGrid = static_cast<TetrisGrid *> (getCurrentGameDrawables()[VECTOR_PLAY_GRID]);
				tGrid->getCurrentPiece()->moveLeft(tGrid->getGrid());
			}
            break;
        case SDL_SCANCODE_RIGHT:
			if (getCurrentGameDrawables().size() != 0) {
				tGrid = static_cast<TetrisGrid *> (getCurrentGameDrawables()[VECTOR_PLAY_GRID]);
				tGrid->getCurrentPiece()->moveRight(tGrid->getGrid());
			}
            break;
        case SDL_SCANCODE_DOWN:
			if (getCurrentGameDrawables().size() != 0) {
				tGrid = static_cast<TetrisGrid *> (getCurrentGameDrawables()[VECTOR_PLAY_GRID]);
				tGrid->getCurrentPiece()->moveDown(tGrid->getGrid());
			}
            break;
		case SDL_SCANCODE_SPACE:
			if (getCurrentGameDrawables().size() != 0) {
				tGrid = static_cast<TetrisGrid *> (getCurrentGameDrawables()[VECTOR_PLAY_GRID]);
				tGrid->getCurrentPiece()->rotate(tGrid->getGrid(), true);
			}
			break;
		case SDL_SCANCODE_ESCAPE:
			getGame()->setGameState(MENU);
			break;
        default:
            break;
    }
	tGrid = NULL;
}

void PlayInputHandler::onKeyHeld(SDL_Scancode key) {
}

void PlayInputHandler::onKeyUp(SDL_Scancode key) {
}

void PlayInputHandler::onQuitGame() {
	setGameState(EXIT);
}
