#ifndef TETRIS_GRID_HPP
#define TETRIS_GRID_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Sprite;
class Timer;
class TetrisPiece;
class Player;

class TetrisGrid : public BaseDrawable {
public:
	TetrisGrid(SDL_Renderer *, int, int, int, int);
	~TetrisGrid();

	void draw(SDL_Renderer *);
    GameState update(Player *);
    void setUpdateTime(int) const;
	
    TetrisPiece * getCurrentPiece() const;
    Uint8 ** getGrid() const;

private:
	void createSprites(SDL_Renderer *);
	Sprite *blockYellow;
	Sprite *blockGreen;
	Sprite *blockGrey;
	Sprite *blockOrange;
	Sprite *blockPurple;
	Sprite *blockRed;
	Sprite *blockBlue;
	Sprite *blockBlank;
    Sprite *gridOutline;
    Timer *tickTimer;
    TetrisPiece *currentPiece;

	Uint8 **grid;
	int blockWidth;
	int blockHeight;
	int gridX, gridY;
	bool updating;

	int clearRows();
	void createRandomPiece();
};

#endif
