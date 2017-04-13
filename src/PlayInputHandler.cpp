#include "PlayInputHandler.hpp"
#include "TetrisGrid.hpp"
#include "TetrisPiece.hpp"

PlayInputHandler::PlayInputHandler(Game *g) : BaseInputHandler(g) {}

void PlayInputHandler::onKeyDown(SDL_Scancode key) {
    switch(key) {
        case SDL_SCANCODE_LEFT:
            break;
        case SDL_SCANCODE_RIGHT:
            break;
        case SDL_SCANCODE_DOWN:
            break;
		case SDL_SCANCODE_SPACE:
			break;
		case SDL_SCANCODE_ESCAPE:
			getGame()->setGameState(MAIN_MENU);
			break;
        default:
            break;
    }
}

void PlayInputHandler::onKeyHeld(SDL_Scancode key) {}

void PlayInputHandler::onKeyUp(SDL_Scancode key) {}

void PlayInputHandler::onDraw(SDL_Renderer *) {}

void PlayInputHandler::onUpdate() {}

void PlayInputHandler::onReset() {}
