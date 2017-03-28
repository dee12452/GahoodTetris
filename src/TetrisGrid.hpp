#ifndef TETRIS_GRID_HPP
#define TETRIS_GRID_HPP

#include "Util.hpp"

class Sprite;
class Timer;
class TetrisPiece;

class TetrisGrid {
public:
	TetrisGrid(SDL_Renderer *, int, int, int, int);
	~TetrisGrid();

	void draw(SDL_Renderer *, SDL_Texture *);
    void update();
    void setUpdateTime(float);
	
    TetrisPiece * getCurrentPiece() const;
    Uint8 ** getGrid() const;
    
    const static int GRID_ROWS;
	const static int GRID_COLUMNS;

private:
	Sprite *blockYellow;
	Sprite *blockBlank;
    Sprite *gridOutline;
	//Sprite *blockRed;
	//Sprite *blockBlue;
	//Sprite *blockGreen;
    Timer *tickTimer;
    TetrisPiece *currentPiece;

	Uint8 **grid;
	int blockWidth;
	int blockHeight;
	int gridX, gridY;
};

#endif
