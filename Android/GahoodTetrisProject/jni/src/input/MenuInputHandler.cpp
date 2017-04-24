#include "../headers/MenuInputHandler.hpp"
#include "../headers/MainMenu.hpp"
#include "../headers/AnimatorHelper.hpp"

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

void MenuInputHandler::onTouch(int x, int y) {
    Sprite *playBtn = SpriteUtil::getSprite(SpriteUtil::SPRITE_PLAY_BUTTON);
    Sprite *exitBtn = SpriteUtil::getSprite(SpriteUtil::SPRITE_EXIT_BUTTON);
    if(AndroidUtil::didTouchSprite(playBtn, x, y)) { 
        getGame()->setGameState(PLAY);
    }
    if(AndroidUtil::didTouchSprite(exitBtn, x, y)) {
        getGame()->setGameState(EXIT);
    }
    playBtn = NULL;
    exitBtn = NULL;
}

void MenuInputHandler::onSwipe(Direction) {}

void MenuInputHandler::onTouchAndHold(int, int) {}

void MenuInputHandler::onPause() {
    AnimatorHelper::getInstance()->stopAnimation();
}

void MenuInputHandler::onResume() {
    AnimatorHelper::getInstance()->startAnimation(ANIMATION_MAIN_MENU);
}

void MenuInputHandler::onBackPressed() { getGame()->setGameState(EXIT); }

void MenuInputHandler::onDestroy() {}
