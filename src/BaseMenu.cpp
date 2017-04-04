#include "BaseMenu.hpp"

BaseMenu::BaseMenu(Game *g,
	SDL_Renderer *renderer, 
	const char *menuSpriteFile, 
	const char *selectorSpriteFile) : BaseInputHandler(g) {

	menuSprite = IMG_LoadTexture(renderer, menuSpriteFile);
	if (menuSprite == NULL) {
		Util::fatalSDLError("Error, failed to load a menu: " + std::string(menuSpriteFile));
	}

	selectorSprite = IMG_LoadTexture(renderer, selectorSpriteFile);
	if (selectorSprite == NULL) {
		Util::fatalSDLError("Error, failed to load a menu's selector: " + std::string(selectorSpriteFile));
	}
	
	menuDestinationRect.x = 0;
	menuDestinationRect.y = 0;
	menuDestinationRect.w = 0;
	menuDestinationRect.h = 0;
	selectorDestinationRect.x = 0;
	selectorDestinationRect.y = 0;
	selectorDestinationRect.w = 0;
	selectorDestinationRect.h = 0;

	menuSourceRect = NULL;
	selectorSourceRect = NULL;

	currentSelection = 0;
}

BaseMenu::BaseMenu(Game *g, 
	SDL_Renderer *renderer,
	const char *menuSpriteFile, 
	const char *selectorSpriteFile, 
	int mX, 
	int mY, 
	int mW, 
	int mH, 
	int sX, 
	int sY, 
	int sW, 
	int sH)
	: BaseMenu(g, renderer, menuSpriteFile, selectorSpriteFile) {

	menuSourceRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));
	selectorSourceRect = (SDL_Rect *)malloc(sizeof(SDL_Rect));

	menuSourceRect->x = mX;
	menuSourceRect->y = mY;
	menuSourceRect->w = mW;
	menuSourceRect->h = mH;
	selectorSourceRect->x = sX;
	selectorSourceRect->y = sY;
	selectorSourceRect->w = sW;
	selectorSourceRect->h = sH;
}

BaseMenu::~BaseMenu() {
	if (menuSprite != NULL) {
		SDL_DestroyTexture(menuSprite);
		menuSprite = NULL;
	}
	if (selectorSprite != NULL) {
		SDL_DestroyTexture(selectorSprite);
		selectorSprite = NULL;
	}
	if (menuSourceRect != NULL) {
		free(menuSourceRect);
		menuSourceRect = NULL;
	}
	if (selectorSourceRect != NULL) {
		free(selectorSourceRect);
		selectorSourceRect = NULL;
	}
}

void BaseMenu::draw(SDL_Renderer *renderer) {
	SDL_RenderCopy(renderer, menuSprite, menuSourceRect, &menuDestinationRect);
	SDL_RenderCopy(renderer, selectorSprite, selectorSourceRect, &selectorDestinationRect);
}

void BaseMenu::onKeyDown(SDL_Scancode scanCode) {
	switch (scanCode) {
		case SDLK_ESCAPE:
			onEscapePressed();
			break;
		case SDLK_UP:
			onUpPressed();
			break;
		case SDLK_DOWN:
			onDownPressed();
			break;
		case SDLK_LEFT:
			onLeftPressed();
			break;
		case SDLK_RIGHT:
			onRightPressed();
			break;
		case SDLK_RETURN:
			onEnterPressed();
			break;
		default:
			break;
	}
}

 void BaseMenu::onEscapePressed() {
	 onQuitGame();
 }

 void BaseMenu::onEnterPressed() {
	 onSelectMenuOption(currentSelection);
 }

void BaseMenu::onKeyHeld(SDL_Scancode) {}

void BaseMenu::onKeyUp(SDL_Scancode) {}

void BaseMenu::onQuitGame() {
	game->setGameState(EXIT);
}

void BaseMenu::setMenuX(int x) { menuDestinationRect.x = x; }
void BaseMenu::setMenuY(int y) { menuDestinationRect.y = y; }
void BaseMenu::setMenuWidth(int w) { menuDestinationRect.w = w; }
void BaseMenu::setMenuHeight(int h) { menuDestinationRect.h = h; }
void BaseMenu::setSelectorX(int x) { selectorDestinationRect.x = x; }
void BaseMenu::setSelectorY(int y) { selectorDestinationRect.y = y; }
void BaseMenu::setSelectorWidth(int w) { selectorDestinationRect.w = w; }
void BaseMenu::setSelectorHeight(int h) { selectorDestinationRect.h = h; }
void BaseMenu::setCurrentSelection(int selection) { currentSelection = selection; }

int BaseMenu::getMenuX() const { return menuDestinationRect.x; }
int BaseMenu::getMenuY() const { return menuDestinationRect.y; }
int BaseMenu::getMenuWidth() const { return menuDestinationRect.w; }
int BaseMenu::getMenuHeight() const { return menuDestinationRect.h; }
int BaseMenu::getSelectorX() const { return selectorDestinationRect.x; }
int BaseMenu::getSelectorY() const { return selectorDestinationRect.y; }
int BaseMenu::getSelectorWidth() const { return selectorDestinationRect.w; }
int BaseMenu::getSelectorHeight() const { return selectorDestinationRect.h; }
int BaseMenu::getCurrentSelection() const { return currentSelection; }