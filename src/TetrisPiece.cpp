#include "TetrisPiece.hpp"
#include "TetrisGrid.hpp"

const int TetrisPiece::ROWS = 3;
const int TetrisPiece::COLUMNS = 3;

TetrisPiece::TetrisPiece(PieceTypes type, int x, int y) {
    this->x = x;
    this->y = y;
    blocks = new Uint8 *[ROWS];
    for(int i = 0; i < ROWS; i++) {
        blocks[i] = new Uint8[COLUMNS];
        for(int j = 0; j < COLUMNS; j++) {
            blocks[i][j] = 0;
        }
    }
    switch(type) {
        case I:
            blocks[1][0] = 1;
            blocks[1][1] = 1;
            blocks[1][2] = 1;
            break;
        case O:
            blocks[0][0] = 1;
            blocks[1][0] = 1;
            blocks[0][1] = 1;
            blocks[1][1] = 1;
            break;
        case T:
            blocks[0][0] = 1;
            blocks[1][0] = 1;
            blocks[2][0] = 1;
            blocks[1][1] = 1;
            break;
        case S:
            blocks[2][0] = 1;
            blocks[1][0] = 1;
            blocks[1][1] = 1;
            blocks[0][1] = 1;
            break;
        case Z:
            blocks[0][0] = 1;
            blocks[1][0] = 1;
            blocks[1][1] = 1;
            blocks[2][1] = 1;
            break;
    }
}

TetrisPiece::~TetrisPiece() {
    if(blocks != NULL)
    {
        for(int i = 0; i < ROWS; i++) {
            delete blocks[i];
            blocks[i] = NULL;
        }
        delete blocks;
        blocks = NULL;
    }
}

void TetrisPiece::setX(int x) { this->x = x; }
void TetrisPiece::setY(int y) { this->y = y; }
int TetrisPiece::getX() const { return x; }
int TetrisPiece::getY() const { return y; }

void TetrisPiece::moveLeft(Uint8 **grid) {
    if(canMoveLeft(grid)) {
        x--;
    }
}

void TetrisPiece::moveRight(Uint8 **grid) {
    if(canMoveRight(grid)) {
        x++;
    }
}

void TetrisPiece::moveDown(Uint8 **grid) {
    if(canMoveDown(grid)) {
        y++;
    }
}

bool TetrisPiece::canMoveLeft(Uint8 **grid) const {
    if(x < 0) return false;
    else if(x == 0) {
        for(int i = 0; i < COLUMNS; i++) {
            if(blocks[0][i] == 1 || grid[x][y + i] == 1)
                return false;
        }
        return true;
    }
    else {
        for(int i = 0; i < COLUMNS; i++) {
            if(blocks[0][i] == 1 && grid[x][y + i] == 1)
                return false;
        }
        return true;
    }
}

bool TetrisPiece::canMoveRight(Uint8 **grid) const {
    if(x > TetrisGrid::GRID_ROWS - ROWS) return false;
    else if(x == TetrisGrid::GRID_ROWS - ROWS) {
        for(int i = 0; i < COLUMNS; i++) {
            if(blocks[ROWS - 1][i] == 1 || grid[x + ROWS][y + i] == 1)
                return false;
        }
        return true;
    }
    else {
        for(int i = 0; i < COLUMNS; i++) {
            if(blocks[ROWS - 1][i] == 1 && grid[x + ROWS][y + i] == 1)
                return false;
        }
        return true;
    }
}

bool TetrisPiece::canMoveDown(Uint8 **grid) const {
    if(y > TetrisGrid::GRID_COLUMNS + COLUMNS) return false;
    else if(y == TetrisGrid::GRID_COLUMNS - COLUMNS) {
        for(int i = 0; i < ROWS; i++) {
            if(blocks[i][COLUMNS - 1] == 1 || grid[x + i][y + COLUMNS] == 1)
                return false;
        }
        return true;
    }
    else {
        for(int i = 0; i < ROWS; i++) {
            if(blocks[i][COLUMNS - 1] == 1 && grid[x + i][y + COLUMNS] == 1)
                return false;
        }
        return true;
    }
}

Uint8 ** TetrisPiece::getBlocks() const {
    return blocks;
}
