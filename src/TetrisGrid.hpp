#ifndef TETRIS_GRID_HPP
#define TETRIS_GRID_HPP

#include "Util.hpp"

class Sprite;

class TetrisGrid {
public:
	TetrisGrid(SDL_Renderer *, int, int, int, int);
	~TetrisGrid();

	void draw(SDL_Renderer *, SDL_Texture *);

private:
	Sprite *blockYellow;
	Sprite *gridOutline;
	//Sprite *blockRed;
	//Sprite *blockBlue;
	//Sprite *blockGreen;

	Uint8 **grid;
	const static int GRID_ROWS;
	const static int GRID_COLUMNS;
	int blockWidth;
	int blockHeight;
	int gridX, gridY;
};

#endif