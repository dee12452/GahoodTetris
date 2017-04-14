#include "../headers/TetrisGrid.hpp"
#include "../headers/Timer.hpp"
#include "../headers/TetrisPiece.hpp"
#include "../headers/SpriteUtil.hpp"
#include "../headers/Player.hpp"

const int TetrisGrid::NEXT_PIECE_X = 16, TetrisGrid::NEXT_PIECE_Y = 3;

TetrisGrid::TetrisGrid(int x, int y) {
	gridX = x;
	gridY = y;
	grid = new Uint8 *[GRID_ROWS];
	for (int i = 0; i < GRID_ROWS; i++) {
		grid[i] = new Uint8[GRID_COLUMNS];
		for (int j = 0; j < GRID_COLUMNS; j++) {
			grid[i][j] = 0;
		}
	}

	nextPiece = new TetrisPiece(static_cast<PieceTypes> (Util::getRandomNumber(0, 6)),
		NEXT_PIECE_X,
		NEXT_PIECE_Y);
	currentPiece = NULL;
	createRandomPiece();

    tickTimer = new Timer(STARTING_BOARD_DELAY_TIME, false);
	updating = true;
}

TetrisGrid::~TetrisGrid() {
    if(currentPiece != NULL) {
        delete currentPiece;
        currentPiece = NULL;
    }
	if (nextPiece != NULL) {
		delete nextPiece;
		nextPiece = NULL;
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
    if(tickTimer != NULL) {
        delete tickTimer;
        tickTimer = NULL;
    }
}

void TetrisGrid::createRandomPiece() {
	PieceTypes nextPieceType = static_cast<PieceTypes> (Util::getRandomNumber(0, 6));
	if(currentPiece != NULL)
		delete currentPiece;
	currentPiece = new TetrisPiece(nextPiece->getPieceType(), GRID_ROWS / 2 - nextPiece->getRows() / 2, 0 - nextPiece->getColumns());
	delete nextPiece;
	nextPiece = new TetrisPiece(nextPieceType, 
		NEXT_PIECE_X,
		NEXT_PIECE_Y);
}

void TetrisGrid::draw(SDL_Renderer *renderer) {
	//Need the below to clear the screen
	SpriteUtil::getSprite(SpriteUtil::SPRITE_BLANK_BLOCK)->draw(renderer);
	//

	//Draw the grid
	int locX = gridX;
    for (int i = 0; i < GRID_ROWS; i++, locX += BLOCK_WIDTH) {
		int locY = gridY;
		for (int j = 0; j < GRID_COLUMNS; j++, locY += BLOCK_HEIGHT) {
			if (grid[i][j] >= 1) {
				Sprite *currBlock;
				switch (grid[i][j] - 1) {
				case I:
					currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_BLUE_BLOCK);
					break;
				case T:
					currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_GREEN_BLOCK);
					break;
				case Z:
					currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_PURPLE_BLOCK);
					break;
				case S:
					currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_ORANGE_BLOCK);
					break;
				case O:
					currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_YELLOW_BLOCK);
					break;
				case J:
					currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_RED_BLOCK);
					break;
				case L:
					currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_GREY_BLOCK);
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

	//Draw the current piece
	locX = (currentPiece->getX() * BLOCK_WIDTH) + gridX;
	if (currentPiece != NULL) {
		for (int i = 0; i < currentPiece->getRows(); i++, locX += BLOCK_WIDTH) {
			int locY = (currentPiece->getY() * BLOCK_HEIGHT) + gridY;
			for (int j = 0; j < currentPiece->getColumns(); j++, locY += BLOCK_HEIGHT) {
				if ((currentPiece->getBlocks())[i][j] == 1 && locY >= 0) {
					Sprite *currBlock;
					switch (static_cast<int> (currentPiece->getPieceType())) {
					case I:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_BLUE_BLOCK);
						break;
					case T:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_GREEN_BLOCK);
						break;
					case Z:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_PURPLE_BLOCK);
						break;
					case S:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_ORANGE_BLOCK);
						break;
					case O:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_YELLOW_BLOCK);
						break;
					case J:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_RED_BLOCK);
						break;
					case L:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_GREY_BLOCK);
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

	//Draw next piece
	locX = (nextPiece->getX() * BLOCK_WIDTH);
	if (nextPiece != NULL) {
		for (int i = 0; i < nextPiece->getRows(); i++, locX += BLOCK_WIDTH) {
			int locY = (nextPiece->getY() * BLOCK_HEIGHT);
			for (int j = 0; j < nextPiece->getColumns(); j++, locY += BLOCK_HEIGHT) {
				if ((nextPiece->getBlocks())[i][j] == 1) {
					Sprite *currBlock;
					switch (static_cast<int> (nextPiece->getPieceType())) {
					case I:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_BLUE_BLOCK);
						break;
					case T:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_GREEN_BLOCK);
						break;
					case Z:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_PURPLE_BLOCK);
						break;
					case S:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_ORANGE_BLOCK);
						break;
					case O:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_YELLOW_BLOCK);
						break;
					case J:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_RED_BLOCK);
						break;
					case L:
						currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_GREY_BLOCK);
						break;
					default:
						std::cout << (int)grid[i][j] - 1 << std::endl;
						Util::fatalError("Error: current block's sprite was not set to anything when drawing the current piece!");
					}
					currBlock->setLocationX(locX);
					currBlock->setLocationY(locY + 10);
					currBlock->draw(renderer);
					currBlock = NULL;
				}
			}
		}
	}

	SpriteUtil::getSprite(SpriteUtil::SPRITE_GRID_BORDER)->draw(renderer);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_NEXT_PIECE_BORDER)->draw(renderer);
}

void TetrisGrid::update(Player *player, GameState &state) {
    if(tickTimer->check() && currentPiece != NULL && updating) {
		if (!currentPiece->moveDown(grid)) {

			player->addPoints(currentPiece->getPieceType());

			if (currentPiece->getY() <= 0) {
				updating = false;
				state = MAIN_MENU;
				return;
			}

			for (int i = 0; i < currentPiece->getRows(); i++) {
				for (int j = 0; j < currentPiece->getColumns(); j++) {
					if ((currentPiece->getBlocks())[i][j] == 1) {
						grid[i + currentPiece->getX()][j + currentPiece->getY()] = static_cast<int> (currentPiece->getPieceType()) + 1;
					}
				}
			}

			player->addPoints(clearRows() * static_cast<int> (currentPiece->getPieceType()));
			createRandomPiece();
		}
    }
}

int TetrisGrid::clearRows() {
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

void TetrisGrid::reset() {
	for (int i = 0; i < GRID_ROWS; i++) {
		for (int j = 0; j < GRID_COLUMNS; j++) {
			grid[i][j] = 0;
		}
	}
	createRandomPiece();
}
