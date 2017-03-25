#include "TetrisGrid.hpp"
#include "TetrisBlock.hpp"

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
	blockYellow->setWidth(blockWidth);
	blockYellow->setHeight(blockHeight);
}

TetrisGrid::~TetrisGrid() {
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
		}
	}
}