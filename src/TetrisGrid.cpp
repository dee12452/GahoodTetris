#include "TetrisGrid.hpp"
#include "TetrisBlock.hpp"
#include "TetrisBorder.hpp"
#include "Timer.hpp"
#include "TetrisPiece.hpp"

const int TetrisGrid::GRID_ROWS = 10;
const int TetrisGrid::GRID_COLUMNS = 20;

TetrisGrid::TetrisGrid(SDL_Renderer *renderer, int x, int y, int width, int height) {
	gridX = x;
	gridY = y;
	blockWidth = width / GRID_ROWS;
	blockHeight = height / GRID_COLUMNS;
	grid = new Uint8 *[GRID_ROWS];
	for (int i = 0; i < GRID_ROWS; i++) {
		grid[i] = new Uint8[GRID_COLUMNS];
		for (int j = 0; j < GRID_COLUMNS; j++) {
			grid[i][j] = 0;
		}
	}
	blockYellow = new TetrisBlock(renderer,
		"../res/tetris_block.png");
	blockBlank = new TetrisBlock(renderer,
		"../res/tetris_block_empty.png");
    gridOutline = new TetrisBorder(renderer,
            "../res/tetris_border.png");
	blockYellow->setWidth(blockWidth);
	blockYellow->setHeight(blockHeight);
	blockBlank->setWidth(blockWidth);
	blockBlank->setHeight(blockHeight);
    gridOutline->setLocationX((DESIRED_WINDOW_WIDTH * 2 - DESIRED_WINDOW_HEIGHT) / 4);
    gridOutline->setLocationY(0);
    gridOutline->setWidth(DESIRED_WINDOW_WIDTH / 2);
    gridOutline->setHeight(DESIRED_WINDOW_HEIGHT);
    currentPiece = new TetrisPiece(PieceTypes::S, GRID_ROWS / 2, 0);
    tickTimer = new Timer(100);
}

TetrisGrid::~TetrisGrid() {
    if(currentPiece != NULL) {
        delete currentPiece;
        currentPiece = NULL;
    }
	if (grid != NULL) {
		for (int i = 0; i < GRID_ROWS; i++) {
			if (grid[i] != NULL) {
				delete grid[i];
				grid[i] = NULL;
			}
		}
		delete grid;
		grid = NULL;
	}
	if (blockYellow != NULL) {
		delete blockYellow;
		blockYellow = NULL;
	}
	if (blockBlank != NULL) {
		delete blockBlank;
		blockBlank = NULL;
	}
	if (gridOutline != NULL) {
		delete gridOutline;
		gridOutline = NULL;
	}
    if(tickTimer != NULL) {
        delete tickTimer;
        tickTimer = NULL;
    }
}

void TetrisGrid::draw(SDL_Renderer *renderer, SDL_Texture *texture) {
    for(int i = 0; i < TetrisPiece::ROWS; i++) {
        for(int j = 0; j < TetrisPiece::COLUMNS; j++) {
            if((currentPiece->getBlocks())[i][j] == 1) {
                grid[i + currentPiece->getX()][j + currentPiece->getY()] = 1;
            }
        }
    }
    int locX = gridX;
    for (int i = 0; i < GRID_ROWS; i++, locX += blockWidth) {
		int locY = gridY;
		for (int j = 0; j < GRID_COLUMNS; j++, locY += blockHeight) {
			if (grid[i][j] == 1) {
				blockYellow->setLocationX(locX);
				blockYellow->setLocationY(locY);
				blockYellow->draw(renderer, texture);
			}
            else {
				blockBlank->setLocationX(locX);
				blockBlank->setLocationY(locY);
				blockBlank->draw(renderer, texture);
            }
		}
	}
    for(int i = 0; i < TetrisPiece::ROWS; i++) {
        for(int j = 0; j < TetrisPiece::COLUMNS; j++) {
            if((currentPiece->getBlocks())[i][j] == 1) {
                grid[i + currentPiece->getX()][j + currentPiece->getY()] = 0;
            }
        }
    }
    gridOutline->draw(renderer, texture);
}

void TetrisGrid::update() {
    if(tickTimer->check()) {
        //currentPiece->moveDown(grid);
    }
}

void TetrisGrid::setUpdateTime(float tickTime) {
    tickTimer->setTargetTime(tickTime);
}

TetrisPiece * TetrisGrid::getCurrentPiece() const {
    return currentPiece;
}

Uint8 ** TetrisGrid::getGrid() const {
    return grid;
}
