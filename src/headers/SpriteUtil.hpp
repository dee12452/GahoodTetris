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

	static Sprite * getSprite(int);

	const static int SPRITE_YELLOW_BLOCK;
	const static int SPRITE_GREEN_BLOCK;
	const static int SPRITE_GREY_BLOCK;
	const static int SPRITE_RED_BLOCK;
	const static int SPRITE_PURPLE_BLOCK;
	const static int SPRITE_BLUE_BLOCK;
	const static int SPRITE_ORANGE_BLOCK;
	const static int SPRITE_BLANK_BLOCK;
	const static int SPRITE_GRID_BORDER;
	const static int SPRITE_NUMBERS_SHEET;
	const static int SPRITE_PLAY_BUTTON;
	const static int SPRITE_EXIT_BUTTON;
	const static int SPRITE_SELECTOR;
	const static int SPRITE_MENU_BG;
	const static int SPRITE_NEXT_PIECE_BORDER;
};

#endif