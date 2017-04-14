#include "../headers/PlayInputHandler.hpp"
#include "../headers/TetrisGrid.hpp"
#include "../headers/TetrisPiece.hpp"
#include "../headers/Player.hpp"

PlayInputHandler::PlayInputHandler(Game *g) : BaseInputHandler(g) {
	tetrisGrid = new TetrisGrid(((2 * DESIRED_WINDOW_WIDTH) - DESIRED_WINDOW_HEIGHT) / 4, 0);
}

PlayInputHandler::~PlayInputHandler() {
	if (tetrisGrid != NULL) {
		delete tetrisGrid;
		tetrisGrid = NULL;
	}
}

void PlayInputHandler::onKeyDown(SDL_Scancode key) {
	TetrisGrid *grid = static_cast<TetrisGrid *> (tetrisGrid);

	switch(key) {
        case SDL_SCANCODE_LEFT:
			grid->getCurrentPiece()->moveLeft(grid->getGrid());
            break;
        case SDL_SCANCODE_RIGHT:
			grid->getCurrentPiece()->moveRight(grid->getGrid());
            break;
        case SDL_SCANCODE_DOWN:
			grid->getCurrentPiece()->moveDown(grid->getGrid());
            break;
		case SDL_SCANCODE_SPACE:
			grid->getCurrentPiece()->rotate(grid->getGrid(), true);
			break;
		case SDL_SCANCODE_ESCAPE:
			static_cast<Player *> (getGame()->getPlayer())->resetPoints();
			getGame()->setGameState(MAIN_MENU);
			break;
        default:
            break;
    }
}

void PlayInputHandler::onKeyHeld(SDL_Scancode key) {}

void PlayInputHandler::onKeyUp(SDL_Scancode key) {}

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
