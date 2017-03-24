#ifndef TETRIS_PIECE_HPP
#define TETRIS_PIECE_HPP

#include "Sprite.hpp"

class TetrisPiece : public Sprite {
public:
	TetrisPiece(SDL_Renderer *, const char *, int, int, int, int, int);
	~TetrisPiece();

	void draw(SDL_Renderer *, SDL_Texture *);

protected:
	void onUpdate();

private:
	Uint8 **piece;
	int rows = 3;
	int columns = 3;
};

#endif