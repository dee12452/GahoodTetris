#include "TetrisBorder.hpp"

TetrisBorder::TetrisBorder(SDL_Renderer *renderer, 
        const char *filename) : Sprite(renderer, 
            filename, 
            true, 
            1) {
}

TetrisBorder::~TetrisBorder() {
}

void TetrisBorder::onUpdate() {
}
