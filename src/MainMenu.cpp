#include "MainMenu.hpp"
#include "SpriteUtil.hpp"

const int MainMenu::BUTTON_Y = 350, MainMenu::BUTTON_X = 115, MainMenu::BUTTON_WIDTH = 70, MainMenu::BUTTON_HEIGHT = 35;

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

	shouldExit = false;
	selectorMoveLeft = true;
}

MainMenu::~MainMenu() {
}

void MainMenu::draw(SDL_Renderer *renderer) {
	SpriteUtil::getSprite(SpriteUtil::SPRITE_MENU_BG)->draw(renderer);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_PLAY_BUTTON)->draw(renderer);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_EXIT_BUTTON)->draw(renderer);
	SpriteUtil::getSprite(SpriteUtil::SPRITE_SELECTOR)->draw(renderer);
}

void MainMenu::update() {
	moveSelectorOnUpdate();
}

void MainMenu::nextSelection() {
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

GameState MainMenu::selectItem() const {
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