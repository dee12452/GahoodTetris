#include "../headers/Sprite.hpp"
#include "../headers/Timer.hpp"

Sprite::Sprite(SDL_Renderer *renderer,
	const char *file,
	int spriteSheetX, 
	int spriteSheetY, 
	int spriteSheetWidth, 
	int spriteSheetHeight) {
	spriteSheet = IMG_LoadTexture(renderer, file);
	if (spriteSheet == NULL) {
		Util::fatalSDLError("Failed to load sprite texture");
	}
	spriteSourceRect.x = spriteSheetX;
	spriteSourceRect.y = spriteSheetY;
	spriteSourceRect.w = spriteSheetWidth;
	spriteSourceRect.h = spriteSheetHeight;
	usingWholeTexture = false;
}

Sprite::Sprite(SDL_Renderer *renderer, 
	const char *file, 
	bool wholeSpriteSheet) : Sprite(renderer, file, 0, 0, 0, 0) {
	usingWholeTexture = wholeSpriteSheet;
}

Sprite::~Sprite() {
	if (spriteSheet != NULL) {
		SDL_DestroyTexture(spriteSheet);
		spriteSheet = NULL;
	}
}

void Sprite::draw(SDL_Renderer *renderer) {
	SDL_Rect destinationRect;
	destinationRect.x = locationX;
	destinationRect.y = locationY;
	destinationRect.w = width;
	destinationRect.h = height;
	if(usingWholeTexture)
		SDL_RenderCopy(renderer, spriteSheet, NULL, &destinationRect);
	else
		SDL_RenderCopy(renderer, spriteSheet, &spriteSourceRect, &destinationRect);
}

void Sprite::draw(SDL_Renderer *renderer, const SDL_Rect &src) {
	SDL_Rect destinationRect;
	destinationRect.x = locationX;
	destinationRect.y = locationY;
	destinationRect.w = width;
	destinationRect.h = height;
	SDL_RenderCopy(renderer, spriteSheet, &src, &destinationRect);
}

int Sprite::getLocationX() const { return locationX; }

int Sprite::getLocationY() const { return locationY; }

int Sprite::getWidth() const { return width; }

int Sprite::getHeight() const { return height; }

SDL_Rect Sprite::getRect() const {
    SDL_Rect rect;
    rect.x = locationX;
    rect.y = locationY;
    rect.w = width;
    rect.h = height;
    return rect;
}

bool Sprite::isUsingWholeTexture() const { return usingWholeTexture; }

void Sprite::setLocationX(int x) { locationX = x; }

void Sprite::setLocationY(int y) { locationY = y; }

void Sprite::setWidth(int w) { width = w; }

void Sprite::setHeight(int h) { height = h; }

void Sprite::setUsingWholeTexture(bool use) { usingWholeTexture = use; }

void Sprite::setRGBColor(Uint8 r, Uint8 g, Uint8 b) {
	SDL_SetTextureColorMod(spriteSheet, r, g, b);
}

void Sprite::setAlpha(Uint8 alpha) {
	SDL_SetTextureAlphaMod(spriteSheet, alpha);
}

void Sprite::setRect(const SDL_Rect &dest) {
	setLocationX(dest.x);
	setLocationY(dest.y);
	setWidth(dest.w);
	setHeight(dest.h);
}
