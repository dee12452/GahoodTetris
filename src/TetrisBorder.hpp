#ifndef TETRIS_BORDER_HPP
#define TETRIS_BORDER_HPP

#include "Util.hpp"
#include "Sprite.hpp"

class TetrisBorder : public Sprite {
public:
    TetrisBorder(SDL_Renderer *, const char *);
    ~TetrisBorder();

protected:
    void onUpdate();
};

#endif
