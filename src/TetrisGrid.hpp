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
	void reset();
    void update(Player *, GameState &);
    void setUpdateTime(int) const;
	
    TetrisPiece * getCurrentPiece() const;
    Uint8 ** getGrid() const;

private:
    Timer *tickTimer;
    TetrisPiece *currentPiece, *nextPiece;

	Uint8 **grid;
	int gridX, gridY;
	static const int NEXT_PIECE_X, NEXT_PIECE_Y;
	bool updating;

	int clearRows();
	void createRandomPiece();
};

#endif
