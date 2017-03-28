#ifndef TETRIS_BLOCK_HPP
#define TETRIS_BLOCK_HPP

#include "Sprite.hpp"

class TetrisBlock : public Sprite {
public:
	TetrisBlock(SDL_Renderer *, const char *);
	~TetrisBlock();

	//Do not need this anymore
	//void draw(SDL_Renderer *, SDL_Texture *);

protected:
	void onUpdate();

private:
	//Uint8 **piece;
	//int rows = 3;
	//int columns = 3;

	void changeColor();
};

#endif
