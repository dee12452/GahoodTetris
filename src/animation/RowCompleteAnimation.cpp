#include "../headers/RowCompleteAnimation.hpp"
#include "../headers/SpriteUtil.hpp"
#include <algorithm>

RowCompleteAnimation::RowCompleteAnimation(int delay, const SDL_Rect &r, int rowCount) : BaseAnimation(delay) {
    blockInfo = r;
    currentAlpha = FULL_ALPHA_VALUE;
    rows = rowCount;
}

RowCompleteAnimation::~RowCompleteAnimation() {}

bool RowCompleteAnimation::isAnimating() const {
    return currentAlpha != 0;
}

void RowCompleteAnimation::onAnimate(SDL_Renderer *renderer) {
    Sprite *whiteBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_WHITE_BLOCK);
    Sprite *emptyBlock = SpriteUtil::getSprite(SpriteUtil::SPRITE_BLANK_BLOCK);
    SDL_Rect whiteRect = whiteBlock->getRect();
    SDL_Rect emptyRect = emptyBlock->getRect();
    SDL_Rect block;
    block.x = blockInfo.x; block.y = blockInfo.y;
    block.w = BLOCK_WIDTH; block.h = BLOCK_HEIGHT;
    whiteBlock->setAlpha(currentAlpha);
    whiteBlock->setRect(block); emptyBlock->setRect(block);
    for(unsigned int row = 0; row < rows; row++) {
        whiteBlock->setLocationY(block.y + (row * BLOCK_HEIGHT));
        emptyBlock->setLocationY(block.y + (row * BLOCK_HEIGHT));
        for(int i = 0; i < GRID_ROWS; i++) {
            whiteBlock->setLocationX(block.x + (i * BLOCK_WIDTH));
            emptyBlock->setLocationX(block.x + (i * BLOCK_WIDTH));
            whiteBlock->draw(renderer);
            emptyBlock->draw(renderer);
        }
    }
    whiteBlock->setRect(whiteRect);
    emptyBlock->setRect(emptyRect);
    whiteBlock = NULL;
    emptyBlock = NULL;
}

void RowCompleteAnimation::onUpdate() {
    currentAlpha = std::max(currentAlpha - 1, 0);

}

void RowCompleteAnimation::parseAnimation(const std::string &) {}
