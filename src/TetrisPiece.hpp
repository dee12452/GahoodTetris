#ifndef TETRIS_PIECE_HPP
#define TETRIS_PIECE_HPP

#include "Util.hpp"

class TetrisPiece {
public:
    TetrisPiece(PieceTypes, int, int);
    ~TetrisPiece();

    int getX() const;
    int getY() const;
	int getRows() const;
	int getColumns() const;
    void setX(int);
    void setY(int);

    bool moveLeft(Uint8 **);
    bool moveRight(Uint8 **);
    bool moveDown(Uint8 **);

	void rotate(Uint8 **, bool);

	Uint8 ** getBlocks() const;
private:
    bool canMoveLeft(Uint8 **) const;
    bool canMoveRight(Uint8 **) const;
	bool canMoveDown(Uint8 **) const;
	void initGrid(int, int);

	void rotateClockwise(Uint8 **);
	void rotateCounterclockwise(Uint8 **);

	int x;
    int y;
	int rows;
	int columns;
    Uint8 **blocks;
};

#endif
