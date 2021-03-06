#include "../headers/TetrisGrid.hpp"
#include "../headers/Timer.hpp"
#include "../headers/TetrisPiece.hpp"
#include "../headers/SpriteUtil.hpp"
#include "../headers/Player.hpp"
#include "../headers/AnimatorHelper.hpp"
#include <algorithm>

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
    tickTimer = new Timer(STARTING_BOARD_DELAY_TIME, false);
	updating = true;
    currentUpdateTime = STARTING_BOARD_DELAY_TIME;
    targetPoints = TARGET_POINTS_FACTOR;
	nextPiece = new TetrisPiece(static_cast<PieceTypes> (Util::getRandomNumber(0, 6)),
		NEXT_PIECE_X,
		NEXT_PIECE_Y);
	currentPiece = NULL;
    needsNewPiece = true;
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
    AnimatorHelper::getInstance()->stopAnimation();
}

void TetrisGrid::createRandomPiece() {
    PieceTypes nextPieceType = static_cast<PieceTypes> (Util::getRandomNumber(0, 6));
    if(currentPiece != NULL) {
		delete currentPiece;
        currentPiece = NULL;
    }
	currentPiece = new TetrisPiece(nextPiece->getPieceType(), GRID_ROWS / 2 - nextPiece->getRows() / 2, 0 - nextPiece->getColumns());
    currentPiece->updatePlacementTimer(currentUpdateTime);
	if(nextPiece != NULL) {
        delete nextPiece;
        nextPiece = NULL;
    }
	nextPiece = new TetrisPiece(nextPieceType, 
		NEXT_PIECE_X,
		NEXT_PIECE_Y);
}

void TetrisGrid::draw(SDL_Renderer *renderer) {
    if(needsNewPiece) {
        needsNewPiece = false;
        createRandomPiece();
    }

    if(!AnimatorHelper::getInstance()->isAnimating()) {
        AnimatorHelper::getInstance()->stopAnimation();
    }

    //Need the below to clear the screen
	SpriteUtil::getSprite(SpriteUtil::SPRITE_BLANK_BLOCK)->draw(renderer);
	//

	//Draw the grid
	int locX = gridX;
    for (int i = 0; i < GRID_ROWS; i++, locX += BLOCK_WIDTH) {
		int locY = gridY;
		for (int j = 0; j < GRID_COLUMNS; j++, locY += BLOCK_HEIGHT) {
			if (grid[i][j] >= 1) {
				Sprite *currBlock = NULL;
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
					Util::printError("Error: current block's sprite was not set to anything when drawing the grid! Defaulting to yellow.");
					currBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_YELLOW_BLOCK);
				}
				currBlock->setLocationX(locX);
				currBlock->setLocationY(locY);
				currBlock->draw(renderer);
				currBlock = NULL;
			}
		}
	}

	if (currentPiece != NULL) {
        //Draw the shadow piece
        TetrisPiece shadowPiece(*currentPiece);
        shadowPiece.forcePlace(grid);
        Uint8 SHADOW_ALPHA = 100;
        locX = (shadowPiece.getX() * BLOCK_WIDTH) + gridX;
		for (int i = 0; i < shadowPiece.getRows(); i++, locX += BLOCK_WIDTH) {
			int locY = (shadowPiece.getY() * BLOCK_HEIGHT) + gridY;
			for (int j = 0; j < shadowPiece.getColumns(); j++, locY += BLOCK_HEIGHT) {
				if ((shadowPiece.getBlocks())[i][j] == 1 && locY >= 0) {
					Sprite *currBlock = NULL;
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
                    currBlock->setAlpha(SHADOW_ALPHA);
					currBlock->draw(renderer);
                    currBlock->setAlpha(FULL_ALPHA_VALUE);
					currBlock = NULL;
				}
			}
        }

        //Draw the current piece
        locX = (currentPiece->getX() * BLOCK_WIDTH) + gridX;
		for (int i = 0; i < currentPiece->getRows(); i++, locX += BLOCK_WIDTH) {
			int locY = (currentPiece->getY() * BLOCK_HEIGHT) + gridY;
			for (int j = 0; j < currentPiece->getColumns(); j++, locY += BLOCK_HEIGHT) {
				if ((currentPiece->getBlocks())[i][j] == 1 && locY >= 0) {
					Sprite *currBlock = NULL;
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
					Sprite *currBlock = NULL;
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
    if(updating && currentPiece != NULL) {
        if(currentPiece->shouldPlace(grid)) {
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

            int rowsCleared = clearRows();
            if(rowsCleared == 1) {
                player->addPoints(2 * static_cast<int> (currentPiece->getPieceType()));
            }
            else {
			    player->addPoints(std::pow(static_cast<int> (currentPiece->getPieceType()), rowsCleared));
            }

            if(player->getPoints() >= targetPoints) {
                targetPoints += TARGET_POINTS_FACTOR;
                player->setLevel(player->getLevel() + 1);
                currentUpdateTime = STARTING_BOARD_DELAY_TIME - (player->getLevel() * UPDATE_TIME_FACTOR);
                currentUpdateTime = std::max(UPDATE_TIME_MINIMUM, currentUpdateTime);
                Util::print("New Update Time: " + std::to_string(currentUpdateTime));
                tickTimer->setTargetMilliseconds(currentUpdateTime, false);
            }
			needsNewPiece = true;
        }
        else {
            if(tickTimer->check())
                currentPiece->moveDown(grid);
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
			if (index < rowsCleared.size() && i == static_cast<unsigned int> (rowsCleared[index])) {
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

    //Animate the row thats cleared
    //TODO: Need to update X and Y and fix visual bugs
    //TODO: Animation file might not get deleted, and will make bugs
    if(rowsCleared.size() > 0) {
        AnimatorHelper::createClearAnimationFile(gridX, rowsCleared[0], rowsCleared.size());
        AnimatorHelper::getInstance()->stopAnimation();
        AnimatorHelper::getInstance()->startAnimation(ANIMATION_CLEAR_ROW);
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
	needsNewPiece = true;
}

void TetrisGrid::placePiece(Player *, GameState &) {
    if(currentPiece == NULL)
        return;
    currentPiece->forcePlace(grid);
    //update(player, gameState);
}
