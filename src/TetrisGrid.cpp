#include "TetrisGrid.hpp"
#include "Timer.hpp"
#include "TetrisPiece.hpp"
#include "Sprite.hpp"
#include "Player.hpp"

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
	createSprites(renderer);
	createRandomPiece();
    tickTimer = new Timer(STARTING_BOARD_DELAY_TIME, false);
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
	if (blockBlue != NULL) {
		delete blockBlue;
		blockBlue = NULL;
	}
	if (blockGreen != NULL) {
		delete blockGreen;
		blockGreen = NULL;
	}
	if (blockGrey != NULL) {
		delete blockGrey;
		blockGrey = NULL;
	}
	if (blockOrange != NULL) {
		delete blockOrange;
		blockOrange = NULL;
	}
	if (blockPurple != NULL) {
		delete blockPurple;
		blockPurple = NULL;
	}
	if(blockRed != NULL) {
		delete blockRed;
		blockRed = NULL;
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

void TetrisGrid::createRandomPiece() {
	int nextPiece = Util::getRandomNumber(0, 6);
	currentPiece = new TetrisPiece(static_cast<PieceTypes> (nextPiece), GRID_ROWS / 2, 0);
}

void TetrisGrid::draw(SDL_Renderer *renderer) {
	//Clear screen by drawing the blank block
	//For the total screen 
	blockBlank->setLocationX(0);
	blockBlank->setLocationY(0);
	blockBlank->draw(renderer);

    int locX = gridX;
    for (int i = 0; i < GRID_ROWS; i++, locX += blockWidth) {
		int locY = gridY;
		for (int j = 0; j < GRID_COLUMNS; j++, locY += blockHeight) {
			if (grid[i][j] >= 1) {
				Sprite *currBlock;
				switch (grid[i][j] - 1) {
				case I:
					currBlock = blockBlue;
					break;
				case T:
					currBlock = blockGreen;
					break;
				case Z:
					currBlock = blockPurple;
					break;
				case S:
					currBlock = blockOrange;
					break;
				case O:
					currBlock = blockYellow;
					break;
				case J:
					currBlock = blockRed;
					break;
				case L:
					currBlock = blockGrey;
					break;
				default:
					std::cout << (int) grid[i][j] - 1 << std::endl;
					Util::fatalError("Error: current block's sprite was not set to anything when drawing the grid!");
				}
				currBlock->setLocationX(locX);
				currBlock->setLocationY(locY);
				currBlock->draw(renderer);
				currBlock = NULL;
			}
		}
	}
	locX = (currentPiece->getX() * blockWidth) + gridX;
	if (currentPiece != NULL) {
		for (int i = 0; i < currentPiece->getRows(); i++, locX += blockWidth) {
			int locY = (currentPiece->getY() * blockHeight) + gridY;
			for (int j = 0; j < currentPiece->getColumns(); j++, locY += blockHeight) {
				if ((currentPiece->getBlocks())[i][j] == 1) {
					Sprite *currBlock;
					switch (static_cast<int> (currentPiece->getPieceType())) {
					case I:
						currBlock = blockBlue;
						break;
					case T:
						currBlock = blockGreen;
						break;
					case Z:
						currBlock = blockPurple;
						break;
					case S:
						currBlock = blockOrange;
						break;
					case O:
						currBlock = blockYellow;
						break;
					case J:
						currBlock = blockRed;
						break;
					case L:
						currBlock = blockGrey;
						break;
					default:
						std::cout << (int) grid[i][j] - 1 << std::endl;
						Util::fatalError("Error: current block's sprite was not set to anything when drawing the current piece!");
					}
					currBlock->setLocationX(locX);
					currBlock->setLocationY(locY);
					currBlock->draw(renderer);
					currBlock = NULL;
				}
			}
		}
	}
    gridOutline->draw(renderer);
}

GameState TetrisGrid::update(Player *player) {
    if(tickTimer->check() && currentPiece != NULL) {
		if (!currentPiece->moveDown(grid)) {

			if (currentPiece->getY() == 0)
				return EXIT;

			player->addPoints(currentPiece->getPieceType());

			for (int i = 0; i < currentPiece->getRows(); i++) {
				for (int j = 0; j < currentPiece->getColumns(); j++) {
					if ((currentPiece->getBlocks())[i][j] == 1) {
						grid[i + currentPiece->getX()][j + currentPiece->getY()] = static_cast<int> (currentPiece->getPieceType()) + 1;
					}
				}
			}

			player->addPoints(clearRows() * static_cast<int> (currentPiece->getPieceType()));
			
			delete currentPiece;
			createRandomPiece();
		}
    }
	return PLAY;
}

int TetrisGrid::clearRows() {
	/* Columns == currRow, Rows = currCols? :( WHY!?
		^^^ that really threw me off, knowledge is power */

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
		for (size_t i = 0, k = rowsCleared.size(), index = 0; i < GRID_COLUMNS; i++) {
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
	
	return rowsCleared.size();
}

void TetrisGrid::setUpdateTime(int time) const {
    tickTimer->setTargetMilliseconds(time, false);
}

TetrisPiece * TetrisGrid::getCurrentPiece() const {
    return currentPiece;
}

Uint8 ** TetrisGrid::getGrid() const {
    return grid;
}

void TetrisGrid::createSprites(SDL_Renderer *renderer) {
	blockYellow = new Sprite(renderer, BLOCK_YELLOW_SPRITE, true);
	blockGreen = new Sprite(renderer, BLOCK_GREEN_SPRITE, true);
	blockGrey = new Sprite(renderer, BLOCK_GREY_SPRITE, true);
	blockOrange = new Sprite(renderer, BLOCK_ORANGE_SPRITE, true);
	blockPurple = new Sprite(renderer, BLOCK_PURPLE_SPRITE, true);
	blockRed = new Sprite(renderer, BLOCK_RED_SPRITE, true);
	blockBlue = new Sprite(renderer, BLOCK_BLUE_SPRITE, true);
	blockBlank = new Sprite(renderer, BLOCK_BLANK_SPRITE, true);
	gridOutline = new Sprite(renderer, GRID_SPRITE, true);

	blockYellow->setWidth(blockWidth);
	blockYellow->setHeight(blockHeight);
	blockGreen->setWidth(blockWidth);
	blockGreen->setHeight(blockHeight);
	blockGrey->setWidth(blockWidth);
	blockGrey->setHeight(blockHeight);
	blockOrange->setWidth(blockWidth);
	blockOrange->setHeight(blockHeight);
	blockPurple->setWidth(blockWidth);
	blockPurple->setHeight(blockHeight);
	blockRed->setWidth(blockWidth);
	blockRed->setHeight(blockHeight);
	blockBlue->setWidth(blockWidth);
	blockBlue->setHeight(blockHeight);
	blockBlank->setWidth(DESIRED_WINDOW_WIDTH);
	blockBlank->setHeight(DESIRED_WINDOW_HEIGHT);
	
	gridOutline->setLocationX((DESIRED_WINDOW_WIDTH * 2 - DESIRED_WINDOW_HEIGHT) / 4);
	gridOutline->setLocationY(0);
	gridOutline->setWidth(DESIRED_WINDOW_WIDTH / 2);
	gridOutline->setHeight(DESIRED_WINDOW_HEIGHT);
}
