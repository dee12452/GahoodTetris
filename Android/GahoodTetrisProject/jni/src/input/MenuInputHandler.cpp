#include "../headers/MenuInputHandler.hpp"
#include "../headers/MainMenu.hpp"
#include "../headers/AnimatorHelper.hpp"
#include "../headers/DisplayUtil.hpp"

MenuInputHandler::MenuInputHandler(Game *g) : BaseInputHandler(g) {
	menu = new MainMenu();
}

MenuInputHandler::~MenuInputHandler() {
	if (menu != NULL) {
		delete menu;
		menu = NULL;
	}
}

void MenuInputHandler::onDraw(SDL_Renderer *renderer) {
    menu->draw(renderer);
}

void MenuInputHandler::onUpdate() {
    menu->update();
}

void MenuInputHandler::onReset() {}

void MenuInputHandler::onTouch(const SDL_TouchFingerEvent &) {}

void MenuInputHandler::onTouchUp(const SDL_TouchFingerEvent &event) {
    int touchX = event.x * DisplayUtil::getScreenWidth();
    int touchY = event.y * DisplayUtil::getScreenHeight();
    Sprite *playBtn = SpriteUtil::getSprite(SpriteUtil::SPRITE_PLAY_BUTTON);
    Sprite *exitBtn = SpriteUtil::getSprite(SpriteUtil::SPRITE_EXIT_BUTTON);
    Sprite *howBtn = SpriteUtil::getSprite(SpriteUtil::SPRITE_HOW_TO_SCREEN);
    if(AndroidUtil::didTouchSprite(playBtn, touchX, touchY)) { 
        getGame()->setGameState(PLAY);
    }
    else if(AndroidUtil::didTouchSprite(exitBtn, touchX, touchY)) {
        getGame()->setGameState(EXIT);
    }
    else if(AndroidUtil::didTouchSprite(howBtn, touchX, touchY)) {
        getGame()->setGameState(HOW_TO_PLAY); 
    }
    playBtn = NULL;
    exitBtn = NULL;
    howBtn = NULL;
}

void MenuInputHandler::onFingerMotion(const SDL_TouchFingerEvent &) {}

void MenuInputHandler::onPause() {
    AnimatorHelper::getInstance()->stopAnimation();
}

void MenuInputHandler::onResume() {
    AnimatorHelper::getInstance()->startAnimation(ANIMATION_MAIN_MENU);
}

void MenuInputHandler::onBackPressed() { getGame()->setGameState(EXIT); }

void MenuInputHandler::onDestroy() {}
