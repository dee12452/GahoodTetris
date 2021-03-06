#include "../headers/MainMenu.hpp"
#include "../headers/SpriteUtil.hpp"

const int MainMenu::BUTTON_Y = 270, MainMenu::BUTTON_X = 115, MainMenu::BUTTON_WIDTH = 70, MainMenu::BUTTON_HEIGHT = 35;

MainMenu::MainMenu() {
	//Set location and dimensions of the sprites
	SpriteUtil::getSprite(SpriteUtil::SPRITE_MENU_BG)->setWidth(DESIRED_WINDOW_WIDTH);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_MENU_BG)->setHeight(DESIRED_WINDOW_HEIGHT);

	SpriteUtil::getSprite(SpriteUtil::SPRITE_PLAY_BUTTON)->setLocationX(BUTTON_X);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_PLAY_BUTTON)->setLocationY(BUTTON_Y);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_PLAY_BUTTON)->setWidth(BUTTON_WIDTH);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_PLAY_BUTTON)->setHeight(BUTTON_HEIGHT);

	SpriteUtil::getSprite(SpriteUtil::SPRITE_EXIT_BUTTON)->setLocationX(BUTTON_X * 3);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_EXIT_BUTTON)->setLocationY(BUTTON_Y);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_EXIT_BUTTON)->setWidth(BUTTON_WIDTH);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_EXIT_BUTTON)->setHeight(BUTTON_HEIGHT);

	SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setLocationX(BUTTON_X - BUTTON_WIDTH);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setLocationY(BUTTON_Y);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setWidth(BUTTON_WIDTH);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setHeight(BUTTON_HEIGHT);
	selectorLocationX = BUTTON_X - BUTTON_WIDTH;

    SpriteUtil::getSprite(SpriteUtil::SPRITE_HOW_BUTTON)->setRect(SpriteUtil::getSprite(SpriteUtil::SPRITE_PLAY_BUTTON)->getRect());
    SpriteUtil::getSprite(SpriteUtil::SPRITE_HOW_BUTTON)->setLocationX(BUTTON_X * 2);
    SpriteUtil::getSprite(SpriteUtil::SPRITE_HOW_BUTTON)->setLocationY(BUTTON_Y * 4 / 3);

	shouldExit = false;
    shouldHelp = false;
	selectorMoveLeft = true;
}

MainMenu::~MainMenu() {
	blockRed = NULL,
	blockYellow = NULL,
	blockBlue = NULL,
	blockPurple = NULL,
	blockOrange = NULL,
	blockGrey = NULL;
}

void MainMenu::draw(SDL_Renderer *renderer) {
	SpriteUtil::getSprite(SpriteUtil::SPRITE_MENU_BG)->draw(renderer);
	Sprite *playBtn = SpriteUtil::getSprite(SpriteUtil::SPRITE_PLAY_BUTTON);
	Sprite *exitBtn = SpriteUtil::getSprite(SpriteUtil::SPRITE_EXIT_BUTTON);
    Sprite *howBtn = SpriteUtil::getSprite(SpriteUtil::SPRITE_HOW_BUTTON);
	playBtn->draw(renderer);
    exitBtn->draw(renderer);
    howBtn->draw(renderer);
    SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->draw(renderer);
    SDL_Rect r; r.x = 50; r.y = 200; r.w = 30; r.h = 30;
    SpriteUtil::drawText(renderer, "Gahood Tetris", r);
    playBtn = NULL;
    exitBtn = NULL;
    howBtn = NULL;
}

void MainMenu::update() {
	moveSelectorOnUpdate();
}

void MainMenu::nextSelection() {
	if(shouldHelp)
        return;
    SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setLocationY(BUTTON_Y);
	if (shouldExit) {
		SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setLocationX(BUTTON_X - BUTTON_WIDTH);
		selectorLocationX = BUTTON_X - BUTTON_WIDTH;
	}
	else {
		SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setLocationX(BUTTON_X * 3 - BUTTON_WIDTH);
		selectorLocationX = BUTTON_X * 3 - BUTTON_WIDTH;
	}
	shouldExit = !shouldExit;
	selectorMoveLeft = true;
}

void MainMenu::previousSelection() {
	nextSelection();
}

void MainMenu::verticalSelection() {
    shouldHelp = !shouldHelp;
    if(shouldHelp) {
        Sprite *howBtn = SpriteUtil::getSprite(SpriteUtil::SPRITE_HOW_BUTTON);
        SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setLocationX(howBtn->getLocationX() - howBtn->getWidth());
        SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setLocationY(howBtn->getLocationY());
		selectorLocationX = howBtn->getLocationX() - howBtn->getWidth();
        howBtn = NULL;
    }
    else {
        nextSelection();
        nextSelection();
    }
}

GameState MainMenu::selectItem() const {
    if(shouldHelp) {
        return HOW_TO_PLAY;
    }
    if(shouldExit)
		return EXIT;
	return PLAY;
}

void MainMenu::moveSelectorOnUpdate() {
	int selectorOffset = 20;
	int selectorMoveSpeed = 2;
	if (selectorMoveLeft) {
		if (SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->getLocationX() == selectorLocationX - selectorOffset) {
			selectorMoveLeft = false;
		}
		SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setLocationX(SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->getLocationX() - selectorMoveSpeed);
	}
	else {
		if (SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->getLocationX() == selectorLocationX) {
			selectorMoveLeft = true;
		}
		SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->setLocationX(SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->getLocationX() + selectorMoveSpeed);
	}
}
