#include "PlayInputHandler.hpp"
#include "TetrisGrid.hpp"
#include "TetrisPiece.hpp"

PlayInputHandler::PlayInputHandler(Game *g) : BaseInputHandler(g) {
}

void PlayInputHandler::onKeyDown(SDL_Scancode key) {
	if (getCurrentGameDrawables().size() == 0) return;
	TetrisGrid *tGrid = static_cast<TetrisGrid *> (getCurrentGameDrawables()[VECTOR_PLAY_GRID]);
    switch(key) {
        case SDL_SCANCODE_LEFT:
			tGrid->getCurrentPiece()->moveLeft(tGrid->getGrid());
            break;
        case SDL_SCANCODE_RIGHT:
			tGrid->getCurrentPiece()->moveRight(tGrid->getGrid());
            break;
        case SDL_SCANCODE_DOWN:
			tGrid->getCurrentPiece()->moveDown(tGrid->getGrid());
            break;
		case SDL_SCANCODE_SPACE:
			tGrid->getCurrentPiece()->rotate(tGrid->getGrid(), true);
        default:
            break;
    }
}

void PlayInputHandler::onKeyHeld(SDL_Scancode key) {
}

void PlayInputHandler::onKeyUp(SDL_Scancode key) {
}

void PlayInputHandler::onQuitGame() {
	setGameState(EXIT);
}
