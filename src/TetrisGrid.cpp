#include "TetrisGrid.hpp"
#include "TetrisBlock.hpp"
#include "TetrisBorder.hpp"
#include "Timer.hpp"
#include "TetrisPiece.hpp"

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

GameState TetrisGrid::update() {
    if(tickTimer->check() && currentPiece != NULL) {
		if (!currentPiece->moveDown(grid)) {

			if (currentPiece->getY() == 0)
				return EXIT;

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
			currentPiece = new TetrisPiece(static_cast<PieceTypes> (nextPiece), GRID_ROWS / 2, 0);
		}
    }
	return PLAY;
}

void TetrisGrid::clearRows() {
	/* Columns == currRow, Rows = currCols? :( WHY!?
		^^^ that really threw me off, knowledge is power*/

	//clearing the rows
	//store the rows in a vector
	std::vector<int> rowsCleared;
	for (int currCol = 0; currCol < GRID_COLUMNS; currCol++) {
		bool clearRow = true;
		for (int currRow = 0; currRow < GRID_ROWS; currRow++) {
			if (grid[currRow][currCol] == 0) {
				clearRow = false;
				break;
			}
		}
		if (clearRow) {
			rowsCleared.push_back(currCol);
		}
	}

	//Shift it all down by making a new grid
	if (rowsCleared.size() > 0) {

		//Init new grid
		Uint8 **newGrid = new Uint8 *[GRID_ROWS];
		for (int i = 0; i < GRID_ROWS; i++) {
			newGrid[i] = new Uint8[GRID_COLUMNS];
			for (int j = 0; j < GRID_COLUMNS; j++) {
				newGrid[i][j] = 0;
			}
		}

		//Copy to new grid, exclude rows that we know are cleared
		for (int i = 0, k = rowsCleared.size(), index = 0; i < GRID_COLUMNS; i++) {
			if (index < rowsCleared.size() && i == rowsCleared[index]) {
				index++;
				continue;
			}
			for (int j = 0; j < GRID_ROWS; j++) {
				newGrid[j][k] = grid[j][i];
			}
			k++;
		}

		//delete old grid, assign old grid to new grid
		for (int i = 0; i < GRID_ROWS; i++) {
			delete[] grid[i];
		}
		delete[] grid;
		grid = newGrid;
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
