#include "TetrisBlock.hpp"

TetrisBlock::TetrisBlock(SDL_Renderer *renderer,
	const char *file) : Sprite(renderer, 
		file, 
		true, 
		1) {
	//changeColor();
}

TetrisBlock::~TetrisBlock() {
	//Util::destroyTetrisPiece(piece);
}

void TetrisBlock::onUpdate() {

}

//Do not need anymore
//void TetrisBlock::draw(SDL_Renderer *renderer, SDL_Texture *texture) {
//	int prevX = this->getLocationX();
//	int prevY = this->getLocationY();
//	int locX = prevX;
//	for (int i = 0; i < rows; i++, locX += this->getWidth()) {
//		int locY = prevY;
//		for (int j = 0; j < columns; j++, locY += this->getHeight()) {
//			if (piece[i][j] == 1) {
//				this->setLocationX(locX);
//				this->setLocationY(locY);
//				Sprite::draw(renderer, texture);
//			}
//		}
//	}
//	this->setLocationX(prevX);
//	this->setLocationY(prevY);
//}

void TetrisBlock::changeColor() {
	int color = Util::getRandomNumber(0, RGB_VARIANTS);
	switch (color)
	{
	case RED:
		setRGBColor(FULL_RGB_VALUE, NO_RGB_VALUE, NO_RGB_VALUE);
		break;
	case BLUE:
		setRGBColor(NO_RGB_VALUE, FULL_RGB_VALUE, NO_RGB_VALUE);
		break;
	case GREEN:
		setRGBColor(NO_RGB_VALUE, NO_RGB_VALUE, FULL_RGB_VALUE);
		break;
	default:
		break;
	}
}
