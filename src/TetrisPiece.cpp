#include "TetrisPiece.hpp"

TetrisPiece::TetrisPiece(SDL_Renderer *renderer, 
	const char *file, 
	int spriteSheetX,
	int spriteSheetY,
	int spriteSheetWidth,
	int spriteSheetHeight,
	int ticksPerSecond) : Sprite(renderer, 
		file, 
		spriteSheetX, 
		spriteSheetY, 
		spriteSheetWidth, 
		spriteSheetHeight, 
		ticksPerSecond) {
	Util::createTetrisPiece(piece, I);
}

TetrisPiece::~TetrisPiece() {
	Util::destroyTetrisPiece(piece);
}

void TetrisPiece::onUpdate() {

}

void TetrisPiece::draw(SDL_Renderer *renderer, SDL_Texture *texture) {
	int prevX = this->getLocationX();
	int prevY = this->getLocationY();
	int locX = prevX;
	int locY = prevY;
	for (int i = 0; i < rows; i++, locX += this->getWidth()) {
		for (int j = 0; j < columns; j++, locY += this->getHeight()) {
			if (piece[i][j] == 1) {
				this->setLocationX(locX);
				this->setLocationY(locY);
				Sprite::draw(renderer, texture);
			}
		}
	}
	this->setLocationX(prevX);
	this->setLocationY(prevY);
}
