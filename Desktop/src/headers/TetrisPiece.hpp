#ifndef TETRIS_PIECE_HPP
#define TETRIS_PIECE_HPP

#include "Util.hpp"

class Timer;

class TetrisPiece {
public:
    TetrisPiece(PieceTypes, int, int);
    TetrisPiece(const TetrisPiece &);
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
    bool shouldPlace(Uint8 **);
    void forcePlace(Uint8 **);

	void rotate(Uint8 **, bool);
    void updatePlacementTimer(int) const;

	Uint8 ** getBlocks() const;
	PieceTypes getPieceType() const;

private:
	PieceTypes type;
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
    Timer *placeTimer;
    bool forcePlacement;
};

#endif
