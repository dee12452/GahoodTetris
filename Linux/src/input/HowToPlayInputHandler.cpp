#include "../headers/HowToPlayInputHandler.hpp"

HowToPlayInputHandler::HowToPlayInputHandler(Game *g) : BaseInputHandler(g) {}

HowToPlayInputHandler::~HowToPlayInputHandler() {}

void HowToPlayInputHandler::onReset() {}

void HowToPlayInputHandler::onDraw(SDL_Renderer *renderer) {
    SpriteUtil::getSprite(SpriteUtil::SPRITE_HOW_TO_SCREEN)->draw(renderer);
}

void HowToPlayInputHandler::onUpdate() {}

void HowToPlayInputHandler::onKeyDown(SDL_Scancode) {}
void HowToPlayInputHandler::onKeyHeld(SDL_Scancode) {}
void HowToPlayInputHandler::onKeyUp(SDL_Scancode key) {
    if(key == SDL_SCANCODE_ESCAPE) {
        getGame()->setGameState(MAIN_MENU);
    }
}
