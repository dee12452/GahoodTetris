#ifndef SPRITE_UTIL_HPP
#define SPRITE_UTIL_HPP

#include "Util.hpp"
#include "Sprite.hpp"

class SpriteUtil {
private:
	SpriteUtil();
	~SpriteUtil();

	static std::vector<Sprite *> gameSprites;

public:
	static void createSprites(SDL_Renderer *);
	static void initSpriteDimensions();
	static void deleteSprites();
    static void drawText(SDL_Renderer *, const std::string &, int, int);
    static void drawText(SDL_Renderer *, const std::string &, const SDL_Rect &);

	static Sprite * getSprite(int);

	const static int SPRITE_YELLOW_BLOCK;
	const static int SPRITE_GREEN_BLOCK;
	const static int SPRITE_GREY_BLOCK;
	const static int SPRITE_RED_BLOCK;
	const static int SPRITE_PURPLE_BLOCK;
	const static int SPRITE_BLUE_BLOCK;
	const static int SPRITE_ORANGE_BLOCK;
	const static int SPRITE_WHITE_BLOCK;
    const static int SPRITE_BLANK_BLOCK;
	const static int SPRITE_GRID_BORDER;
	const static int SPRITE_NUMBERS_SHEET;
	const static int SPRITE_PLAY_BUTTON;
	const static int SPRITE_EXIT_BUTTON;
    const static int SPRITE_HOW_BUTTON;
	const static int SPRITE_SELECTOR;
	const static int SPRITE_MENU_BG;
	const static int SPRITE_NEXT_PIECE_BORDER;
    const static int SPRITE_A; 
    const static int SPRITE_B; 
    const static int SPRITE_C; 
    const static int SPRITE_D; 
    const static int SPRITE_E; 
    const static int SPRITE_F; 
    const static int SPRITE_G; 
    const static int SPRITE_H; 
    const static int SPRITE_I; 
    const static int SPRITE_J; 
    const static int SPRITE_K; 
    const static int SPRITE_L; 
    const static int SPRITE_M; 
    const static int SPRITE_N; 
    const static int SPRITE_O; 
    const static int SPRITE_P; 
    const static int SPRITE_Q; 
    const static int SPRITE_R; 
    const static int SPRITE_S; 
    const static int SPRITE_T; 
    const static int SPRITE_U;
    const static int SPRITE_V;
    const static int SPRITE_W;
    const static int SPRITE_X;
    const static int SPRITE_Y;
    const static int SPRITE_Z;
    const static int SPRITE_INDICATOR_LEFT;
    const static int SPRITE_INDICATOR_RIGHT;
    const static int SPRITE_HOW_TO_SCREEN;
};

#endif
