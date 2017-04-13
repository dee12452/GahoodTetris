#include "MenuInputHandler.hpp"
#include "MainMenu.hpp"

MenuInputHandler::MenuInputHandler(Game *g) : BaseInputHandler(g) {
	menu = new MainMenu();
}

MenuInputHandler::~MenuInputHandler() {
	if (menu != NULL) {
		delete menu;
		menu = NULL;
	}
}

void MenuInputHandler::onKeyDown(SDL_Scancode code) {
	switch (code) {
	case SDL_SCANCODE_LEFT:
		menu->previousSelection();
		break;
	case SDL_SCANCODE_RIGHT:
		menu->nextSelection();
		break;
	case SDL_SCANCODE_RETURN:
		getGame()->setGameState(menu->selectItem());
		break;
	case SDL_SCANCODE_ESCAPE:
		getGame()->setGameState(EXIT);
		break;
	default:
		break;
	}
}

void MenuInputHandler::onKeyHeld(SDL_Scancode) {}

void MenuInputHandler::onKeyUp(SDL_Scancode) {}

void MenuInputHandler::onDraw(SDL_Renderer *renderer) {
	menu->draw(renderer);
}

void MenuInputHandler::onUpdate() {
	menu->update();
}

void MenuInputHandler::onReset() {}