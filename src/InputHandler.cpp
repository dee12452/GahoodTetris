#include "InputHandler.hpp"
#include "Game.hpp"
#include "TetrisGrid.hpp"
#include "TetrisPiece.hpp"

InputHandler::InputHandler(Game *g) {
	game = g;
}

void InputHandler::onKeyDown(SDL_Scancode key) {
	TetrisGrid *tGrid = static_cast<TetrisGrid *> (game->getTetrisGrid());
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

void InputHandler::onKeyHeld(SDL_Scancode key) {
}

void InputHandler::onKeyUp(SDL_Scancode key) {
}

void InputHandler::onQuitGame() {
	game->setGameState(EXIT);
}

Game * InputHandler::getGame() const {
	return game;
}
