#include "SpriteUtil.hpp"
#include "Sprite.hpp"

const int SpriteUtil::SPRITE_YELLOW_BLOCK = 0;
const int SpriteUtil::SPRITE_GREEN_BLOCK = 1;
const int SpriteUtil::SPRITE_GREY_BLOCK = 2;
const int SpriteUtil::SPRITE_RED_BLOCK = 3;
const int SpriteUtil::SPRITE_PURPLE_BLOCK = 4;
const int SpriteUtil::SPRITE_BLUE_BLOCK = 5;
const int SpriteUtil::SPRITE_ORANGE_BLOCK = 6;
const int SpriteUtil::SPRITE_BLANK_BLOCK = 7;
const int SpriteUtil::SPRITE_GRID_BORDER = 8;
const int SpriteUtil::SPRITE_NUMBERS_SHEET = 9;
const int SpriteUtil::SPRITE_PLAY_BUTTON = 10;
const int SpriteUtil::SPRITE_EXIT_BUTTON = 11;
const int SpriteUtil::SPRITE_SELECTOR = 12;
const int SpriteUtil::SPRITE_MENU_BG = 13;
const int SpriteUtil::SPRITE_NEXT_PIECE_BORDER = 14;

std::vector<Sprite *> SpriteUtil::gameSprites;

SpriteUtil::SpriteUtil() {}

SpriteUtil::~SpriteUtil() {}

void SpriteUtil::createSprites(SDL_Renderer *renderer) {
	gameSprites.push_back(new Sprite(renderer,
		BLOCK_YELLOW_SPRITE_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		BLOCK_GREEN_SPRITE_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		BLOCK_GREY_SPRITE_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		BLOCK_RED_SPRITE_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		BLOCK_PURPLE_SPRITE_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		BLOCK_BLUE_SPRITE_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		BLOCK_ORANGE_SPRITE_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		BLOCK_BLANK_SPRITE_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		GRID_SPRITE_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		NUMBERS_SPRITE_SHEET_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_PLAY_BUTTON_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_EXIT_BUTTON_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_SELECTOR_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_MENU_BG_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_NEXT_BORDER_FILE_LOCATION,
		true));
	initSpriteDimensions();
}

void SpriteUtil::deleteSprites() {
	for (size_t i = 0; i < gameSprites.size(); i++) {
		if (gameSprites[i] != NULL) {
			delete gameSprites[i];
			gameSprites[i] = NULL;
		}
	}
}

Sprite * SpriteUtil::getSprite(int desiredSprite) {
	if (desiredSprite >= static_cast<int> (gameSprites.size()))
		return NULL;
	return gameSprites[desiredSprite];
}

void SpriteUtil::initSpriteDimensions() {
	gameSprites[SPRITE_YELLOW_BLOCK]->setWidth(BLOCK_WIDTH);
	gameSprites[SPRITE_YELLOW_BLOCK]->setHeight(BLOCK_HEIGHT);

	gameSprites[SPRITE_GREEN_BLOCK]->setWidth(BLOCK_WIDTH);
	gameSprites[SPRITE_GREEN_BLOCK]->setHeight(BLOCK_HEIGHT);

	gameSprites[SPRITE_GREY_BLOCK]->setWidth(BLOCK_WIDTH);
	gameSprites[SPRITE_GREY_BLOCK]->setHeight(BLOCK_HEIGHT);

	gameSprites[SPRITE_ORANGE_BLOCK]->setWidth(BLOCK_WIDTH);
	gameSprites[SPRITE_ORANGE_BLOCK]->setHeight(BLOCK_HEIGHT);

	gameSprites[SPRITE_PURPLE_BLOCK]->setWidth(BLOCK_WIDTH);
	gameSprites[SPRITE_PURPLE_BLOCK]->setHeight(BLOCK_HEIGHT);

	gameSprites[SPRITE_RED_BLOCK]->setWidth(BLOCK_WIDTH);
	gameSprites[SPRITE_RED_BLOCK]->setHeight(BLOCK_HEIGHT);

	gameSprites[SPRITE_BLUE_BLOCK]->setWidth(BLOCK_WIDTH);
	gameSprites[SPRITE_BLUE_BLOCK]->setHeight(BLOCK_HEIGHT);

	gameSprites[SPRITE_BLANK_BLOCK]->setWidth(DESIRED_WINDOW_WIDTH);
	gameSprites[SPRITE_BLANK_BLOCK]->setHeight(DESIRED_WINDOW_HEIGHT);

	gameSprites[SPRITE_GRID_BORDER]->setLocationX((DESIRED_WINDOW_WIDTH * 2 - DESIRED_WINDOW_HEIGHT) / 4);
	gameSprites[SPRITE_GRID_BORDER]->setLocationY(0);
	gameSprites[SPRITE_GRID_BORDER]->setWidth(DESIRED_WINDOW_WIDTH / 2);
	gameSprites[SPRITE_GRID_BORDER]->setHeight(DESIRED_WINDOW_HEIGHT);

	gameSprites[SPRITE_NEXT_PIECE_BORDER]->setWidth(BLOCK_WIDTH * 5);
	gameSprites[SPRITE_NEXT_PIECE_BORDER]->setHeight(BLOCK_HEIGHT * 5);
	gameSprites[SPRITE_NEXT_PIECE_BORDER]->setLocationX(DESIRED_WINDOW_WIDTH - (BLOCK_WIDTH * 5));
	gameSprites[SPRITE_NEXT_PIECE_BORDER]->setLocationY((BLOCK_WIDTH * 3) - 30);
}
