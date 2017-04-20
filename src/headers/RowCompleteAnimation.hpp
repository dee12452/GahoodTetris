#ifndef ROW_COMPLETE_ANIMATION_HPP
#define ROW_COMPLETE_ANIMATION_HPP

#include "BaseAnimation.hpp"

class RowCompleteAnimation : public BaseAnimation {
public:
    RowCompleteAnimation(int, const SDL_Rect &, int);
    ~RowCompleteAnimation();
    bool isAnimating() const override;

protected:
    void onAnimate(SDL_Renderer *) override;
    void onUpdate() override;
    void parseAnimation(const std::string &) override;

private:
    SDL_Rect blockInfo;
    Uint8 currentAlpha, rows;
};

#endif
