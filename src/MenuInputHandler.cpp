#include "MenuInputHandler.hpp"
#include "MainMenu.hpp"

MenuInputHandler::MenuInputHandler(Game *g) : BaseInputHandler(g) {

}

MenuInputHandler::~MenuInputHandler() {

}

void MenuInputHandler::onKeyDown(SDL_Scancode code) {
	MainMenu *menu = NULL;
	switch (code) {
	case SDL_SCANCODE_LEFT:
		menu = static_cast<MainMenu *> (getGame()->getGameDrawables()[VECTOR_MENU][VECTOR_MENU_MAIN]);
		if (menu == NULL) Util::fatalError("Failed to cast to a main menu error");
		menu->previousSelection();
		break;
	case SDL_SCANCODE_RIGHT:
		menu = static_cast<MainMenu *> (getGame()->getGameDrawables()[VECTOR_MENU][VECTOR_MENU_MAIN]);
		if (menu == NULL) Util::fatalError("Failed to cast to a main menu error");
		menu->nextSelection();
		break;
	case SDL_SCANCODE_RETURN:
		menu = static_cast<MainMenu *> (getGame()->getGameDrawables()[VECTOR_MENU][VECTOR_MENU_MAIN]);
		getGame()->setGameState(menu->selectItem());
		break;
	default:
		break;
	}
}

void MenuInputHandler::onKeyHeld(SDL_Scancode) {
}

void MenuInputHandler::onKeyUp(SDL_Scancode) {

}