#ifndef TETRIS_PIECE_HPP
#define TETRIS_PIECE_HPP

#include "Util.hpp"

class TetrisPiece {
public:
    TetrisPiece(PieceTypes, int, int);
    ~TetrisPiece();

    int getX() const;
    int getY() const;
    void setX(int);
    void setY(int);

    void moveLeft(Uint8 **);
    void moveRight(Uint8 **);
    void moveDown(Uint8 **);
    Uint8 ** getBlocks() const;

    const static int ROWS;
    const static int COLUMNS;
private:
    bool canMoveLeft(Uint8 **) const;
    bool canMoveRight(Uint8 **) const;
    bool canMoveDown(Uint8 **) const;
    int x;
    int y;
    Uint8 **blocks;
};

#endif
