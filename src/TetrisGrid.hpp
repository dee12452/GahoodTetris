#ifndef TETRIS_GRID_HPP
#define TETRIS_GRID_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Timer;
class TetrisPiece;
class Player;

class TetrisGrid : public BaseDrawable {
public:
	TetrisGrid(int, int);
	~TetrisGrid();

	void draw(SDL_Renderer *);
    GameState update(Player *);
    void setUpdateTime(int) const;
	
    TetrisPiece * getCurrentPiece() const;
    Uint8 ** getGrid() const;

private:
    Timer *tickTimer;
    TetrisPiece *currentPiece;

	Uint8 **grid;
	int gridX, gridY;
	bool updating;

	int clearRows();
	void createRandomPiece();
};

#endif
