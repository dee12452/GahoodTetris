#include "Sprite.hpp"
#include "Timer.hpp"

const int Sprite::DEFAULT_TICKS_PER_SECOND = 100;

Sprite::Sprite(SDL_Renderer *renderer,
	const char *file,
	int spriteSheetX, 
	int spriteSheetY, 
	int spriteSheetWidth, 
	int spriteSheetHeight, 
	int ticksPerSecond) {
	spriteSheet = IMG_LoadTexture(renderer, file);
	spriteSourceRect.x = spriteSheetX;
	spriteSourceRect.y = spriteSheetY;
	spriteSourceRect.w = spriteSheetWidth;
	spriteSourceRect.h = spriteSheetHeight;
	onTickTimer = new Timer(ticksPerSecond);
}

Sprite::~Sprite() {
	if (onTickTimer != NULL) {
		delete onTickTimer;
		onTickTimer = NULL;
	}
	if (spriteSheet != NULL) {
		SDL_DestroyTexture(spriteSheet);
		spriteSheet = NULL;
	}
}

void Sprite::update() {
	if (onTickTimer->check()) {
		onUpdate();
	}
}

void Sprite::draw(SDL_Renderer *renderer, SDL_Texture *target) {
	SDL_Rect destinationRect;
	destinationRect.x = locationX;
	destinationRect.y = locationY;
	destinationRect.w = width;
	destinationRect.h = height;
	SDL_SetRenderTarget(renderer, target);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, spriteSheet, &spriteSourceRect, &destinationRect);
	SDL_SetRenderTarget(renderer, NULL);
}

int Sprite::getLocationX() const { return locationX; }

int Sprite::getLocationY() const { return locationY; }

int Sprite::getWidth() const { return width; }

int Sprite::getHeight() const { return height; }

SDL_Texture * Sprite::getTexture() const { return spriteSheet; }

void Sprite::setLocationX(int x) { locationX = x; }

void Sprite::setLocationY(int y) { locationY = y; }

void Sprite::setWidth(int w) { width = w; }

void Sprite::setHeight(int h) { height = h; }