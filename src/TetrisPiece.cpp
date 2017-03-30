#include "TetrisPiece.hpp"
#include "TetrisGrid.hpp"

TetrisPiece::TetrisPiece(PieceTypes type, int x, int y) {
    this->x = x;
    this->y = y;
    switch(type) {
        case I:
			initGrid(1, 3);
            blocks[0][0] = 1;
            blocks[0][1] = 1;
            blocks[0][2] = 1;
            break;
        case O:
			initGrid(2, 2);
            blocks[0][0] = 1;
            blocks[1][0] = 1;
            blocks[0][1] = 1;
            blocks[1][1] = 1;
            break;
        case T:
			initGrid(3, 2);
            blocks[0][0] = 1;
            blocks[1][0] = 1;
            blocks[2][0] = 1;
            blocks[1][1] = 1;
            break;
        case S:
			initGrid(3, 2);
            blocks[2][0] = 1;
            blocks[1][0] = 1;
            blocks[1][1] = 1;
            blocks[0][1] = 1;
            break;
        case Z:
			initGrid(3, 2);
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
        for(int i = 0; i < rows; i++) {
            delete[] blocks[i];
            blocks[i] = NULL;
        }
        delete[] blocks;
        blocks = NULL;
    }
}

void TetrisPiece::setX(int x) { this->x = x; }
void TetrisPiece::setY(int y) { this->y = y; }
int TetrisPiece::getX() const { return x; }
int TetrisPiece::getY() const { return y; }
int TetrisPiece::getRows() const { return rows; }
int TetrisPiece::getColumns() const { return columns; }

bool TetrisPiece::moveLeft(Uint8 **grid) {
    if(canMoveLeft(grid)) {
        x--;
		return true;
    }
	return false;
}

bool TetrisPiece::moveRight(Uint8 **grid) {
    if(canMoveRight(grid)) {
        x++;
		return true;
    }
	return false;
}

bool TetrisPiece::moveDown(Uint8 **grid) {
    if(canMoveDown(grid)) {
        y++;
		return true;
    }
	return false;
}

bool TetrisPiece::canMoveLeft(Uint8 **grid) const {
    if(x <= 0) return false;
    else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (blocks[i][j] == 1 && grid[x + i - 1][y + j] == 1)
					return false;
			}
		}
        return true;
    }
}

bool TetrisPiece::canMoveRight(Uint8 **grid) const {
    if(x >= TetrisGrid::GRID_ROWS - rows) return false;
    else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (blocks[i][j] == 1 && grid[x + i + 1][y + j] == 1)
					return false;
			}
		}
        return true;
    }
}

bool TetrisPiece::canMoveDown(Uint8 **grid) const {
    if(y >= TetrisGrid::GRID_COLUMNS - columns) return false;
    else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (blocks[i][j] == 1 && grid[x + i][y + j + 1] == 1)
					return false;
			}
		}
        return true;
    }
}

Uint8 ** TetrisPiece::getBlocks() const {
    return blocks;
}

void TetrisPiece::initGrid(int row, int col) {
	rows = row;
	columns = col;
	blocks = new Uint8 *[rows];
	for (int i = 0; i < rows; i++) {
		blocks[i] = new Uint8[columns];
		for (int j = 0; j < columns; j++) {
			blocks[i][j] = 0;
		}
	}
}
