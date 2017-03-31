#include "InputHandler.hpp"
#include "Game.hpp"
#include "TetrisGrid.hpp"
#include "TetrisPiece.hpp"

InputHandler::InputHandler(Game *g) {
	game = g;
}

void InputHandler::onKeyDown(SDL_Scancode key) {
    switch(key) {
        case SDL_SCANCODE_LEFT:
            game->getTetrisGrid()->getCurrentPiece()->moveLeft(game->getTetrisGrid()->getGrid());
            break;
        case SDL_SCANCODE_RIGHT:
            game->getTetrisGrid()->getCurrentPiece()->moveRight(game->getTetrisGrid()->getGrid());
            break;
        case SDL_SCANCODE_DOWN:
            game->getTetrisGrid()->getCurrentPiece()->moveDown(game->getTetrisGrid()->getGrid());
            break;
		case SDL_SCANCODE_SPACE:
			game->getTetrisGrid()->getCurrentPiece()->rotate(game->getTetrisGrid()->getGrid(), true);
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
