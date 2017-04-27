#include "../headers/HowToPlayInputHandler.hpp"

HowToPlayInputHandler::HowToPlayInputHandler(Game *g) : BaseInputHandler(g) {}

HowToPlayInputHandler::~HowToPlayInputHandler() {}

void HowToPlayInputHandler::onReset() {}
void HowToPlayInputHandler::onUpdate() {}

void HowToPlayInputHandler::onDraw(SDL_Renderer *renderer) {
    SpriteUtil::getSprite(SpriteUtil::SPRITE_HOW_TO_SCREEN)->draw(renderer);
}

void HowToPlayInputHandler::onBackPressed() {
    getGame()->setGameState(MAIN_MENU);
}

void HowToPlayInputHandler::onTouch(const SDL_TouchFingerEvent &) {}
void HowToPlayInputHandler::onTouchUp(const SDL_TouchFingerEvent &) {}
void HowToPlayInputHandler::onFingerMotion(const SDL_TouchFingerEvent &) {}

void HowToPlayInputHandler::onPause() {}
void HowToPlayInputHandler::onResume() { onBackPressed(); }
void HowToPlayInputHandler::onDestroy() {}
