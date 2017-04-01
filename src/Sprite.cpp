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
	if (spriteSheet == NULL) {
		Util::fatalSDLError("Failed to load sprite texture");
	}
	spriteSourceRect.x = spriteSheetX;
	spriteSourceRect.y = spriteSheetY;
	spriteSourceRect.w = spriteSheetWidth;
	spriteSourceRect.h = spriteSheetHeight;
	onTickTimer = new Timer(ticksPerSecond, true);
	usingWholeTexture = false;
}

Sprite::Sprite(SDL_Renderer *renderer, 
	const char *file, 
	bool wholeSpriteSheet, 
	int ticksPerSecond) : Sprite(renderer, file, 0, 0, 0, 0, ticksPerSecond) {
	usingWholeTexture = wholeSpriteSheet;
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

int Sprite::getLocationX() const { return locationX; }

int Sprite::getLocationY() const { return locationY; }

int Sprite::getWidth() const { return width; }

int Sprite::getHeight() const { return height; }

bool Sprite::isUsingWholeTexture() const { return usingWholeTexture; }

SDL_Texture * Sprite::getTexture() const { return spriteSheet; }

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
