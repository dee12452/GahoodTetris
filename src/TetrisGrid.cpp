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
	currentPiece = new TetrisPiece(PieceTypes::I, GRID_ROWS / 2, 0);
    tickTimer = new Timer(1.5f);
	updating = false;
}

TetrisGrid::~TetrisGrid() {
    if(currentPiece != NULL) {
        delete currentPiece;
        currentPiece = NULL;
    }
	if (grid != NULL) {
		for (int i = 0; i < GRID_ROWS; i++) {
			if (grid[i] != NULL) {
				delete[] grid[i];
				grid[i] = NULL;
			}
		}
		delete[] grid;
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
	//if (currentPiece != NULL) {
	//	for (int i = 0; i < currentPiece->getRows(); i++) {
	//		for (int j = 0; j < currentPiece->getColumns(); j++) {
	//			if ((currentPiece->getBlocks())[i][j] == 1) {
	//				grid[i + currentPiece->getX()][j + currentPiece->getY()] = 1;
	//			}
	//		}
	//	}
	//}
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
	locX = (currentPiece->getX() * blockWidth) + gridX;
	if (currentPiece != NULL) {
		for (int i = 0; i < currentPiece->getRows(); i++, locX += blockWidth) {
			int locY = (currentPiece->getY() * blockHeight) + gridY;
			for (int j = 0; j < currentPiece->getColumns(); j++, locY += blockHeight) {
				if ((currentPiece->getBlocks())[i][j] == 1) {
					blockYellow->setLocationX(locX);
					blockYellow->setLocationY(locY);
					blockYellow->draw(renderer, texture);
				}
			}
		}
	}
    gridOutline->draw(renderer, texture);
}

void TetrisGrid::update() {
    if(tickTimer->check() && currentPiece != NULL) {
		if (!currentPiece->moveDown(grid)) {
			for (int i = 0; i < currentPiece->getRows(); i++) {
				for (int j = 0; j < currentPiece->getColumns(); j++) {
					if ((currentPiece->getBlocks())[i][j] == 1) {
						grid[i + currentPiece->getX()][j + currentPiece->getY()] = 1;
					}
				}
			}

			clearRows();
			
			delete currentPiece;
			int nextPiece = Util::getRandomNumber(0, 4);
			currentPiece = new TetrisPiece(/*static_cast<PieceTypes> (nextPiece) */ PieceTypes::I, GRID_ROWS / 2, 0);
		}
    }
}

void TetrisGrid::clearRows() {
	/* Columns == currRow, Rows = currCols? :( WHY!? */
	for (int currCol = 0; currCol < GRID_COLUMNS; currCol++) {
		bool clearRow = true;
		for (int currRow = 0; currRow < GRID_ROWS; currRow++) {
			if (grid[currRow][currCol] == 0) {
				clearRow = false;
				break;
			}
		}
		if (clearRow) {
			for (int currRow = 0; currRow < GRID_ROWS; currRow++) {
				grid[currRow][currCol] = 0;
			}
		}
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
