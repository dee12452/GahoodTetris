#include "../headers/SpriteUtil.hpp"
#include "../headers/Sprite.hpp"

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
const int SpriteUtil::SPRITE_A = 15;
const int SpriteUtil::SPRITE_B = 16;
const int SpriteUtil::SPRITE_C = 17;
const int SpriteUtil::SPRITE_D = 18;
const int SpriteUtil::SPRITE_E = 19;
const int SpriteUtil::SPRITE_F = 20;
const int SpriteUtil::SPRITE_G = 21;
const int SpriteUtil::SPRITE_H = 22;
const int SpriteUtil::SPRITE_I = 23;
const int SpriteUtil::SPRITE_J = 24;
const int SpriteUtil::SPRITE_K = 25;
const int SpriteUtil::SPRITE_L = 26;
const int SpriteUtil::SPRITE_M = 27;
const int SpriteUtil::SPRITE_N = 28;
const int SpriteUtil::SPRITE_O = 29;
const int SpriteUtil::SPRITE_P = 30;
const int SpriteUtil::SPRITE_Q = 31;
const int SpriteUtil::SPRITE_R = 32;
const int SpriteUtil::SPRITE_S = 33;
const int SpriteUtil::SPRITE_T = 34;
const int SpriteUtil::SPRITE_U = 35;
const int SpriteUtil::SPRITE_V = 36;
const int SpriteUtil::SPRITE_W = 37;
const int SpriteUtil::SPRITE_X = 38;
const int SpriteUtil::SPRITE_Y = 39;
const int SpriteUtil::SPRITE_Z = 40;

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
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_A_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_B_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_C_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_D_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_E_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_F_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_G_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_H_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_I_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_J_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_K_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_L_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_M_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_N_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_O_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_P_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_Q_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_R_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_S_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_T_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_U_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_V_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_W_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_X_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_Y_FILE_LOCATION,
		true));
	gameSprites.push_back(new Sprite(renderer,
		SPRITE_Z_FILE_LOCATION,
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
	if (desiredSprite >= static_cast<int> (gameSprites.size()) || desiredSprite < 0)
		return NULL;
	return gameSprites[desiredSprite];
}

void SpriteUtil::initSpriteDimensions() {
    //Set dimensions for each block
    for(int i = 0; i < 7; i++) {
        gameSprites[i]->setWidth(BLOCK_WIDTH);
        gameSprites[i]->setHeight(BLOCK_HEIGHT);
    }

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

    //Set dimensions for the font sprites (A - Z)
    for(int i = 15; i <= 40; i++) {
        gameSprites[i]->setWidth(BLOCK_WIDTH * 2);
        gameSprites[i]->setHeight(BLOCK_HEIGHT * 2);
    }
}

void SpriteUtil::drawText(SDL_Renderer *renderer, const std::string &s, int x, int y) {
    SDL_Rect r;
    r.x = x; r.y = y;
    r.w = BLOCK_WIDTH * 2; r.h = BLOCK_HEIGHT * 2;
    drawText(renderer, s, r);
}

void SpriteUtil::drawText(SDL_Renderer *renderer, const std::string &s, const SDL_Rect &r) {
    for(unsigned int i = 0; i < s.length(); i++) {
        int sprId = ((int) s[i] - 'A') + 15;
        if(sprId < 0 || sprId > 40) {
            sprId = ((int) s[i] - 'a') + 15;
            if(sprId < 0 || sprId > 40) {
                continue; 
            }
        }
        Sprite *spr = getSprite(sprId);
        SDL_Rect originalRect = spr->getRect();
        spr->setLocationX(r.x + (i * r.w));
        spr->setLocationY(r.y);
        spr->setWidth(r.w);
        spr->setHeight(r.h);
        spr->draw(renderer);
        spr->setRect(originalRect);
    }
}
