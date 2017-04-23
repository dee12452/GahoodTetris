#include "../headers/MenuInputHandler.hpp"
#include "../headers/MainMenu.hpp"

MenuInputHandler::MenuInputHandler(Game *g) : BaseInputHandler(g) {
	menu = new MainMenu();
}

MenuInputHandler::~MenuInputHandler() {
	if (menu != NULL) {
		delete menu;
		menu = NULL;
	}
}

void MenuInputHandler::onDraw(SDL_Renderer *renderer) {
    menu->draw(renderer);
}

void MenuInputHandler::onUpdate() {
    menu->update();
}

void MenuInputHandler::onReset() {}

void MenuInputHandler::onTouch(int, int) {}

void MenuInputHandler::onSwipe() {}

void MenuInputHandler::onTouchAndHold(int, int) {}

void MenuInputHandler::onPause() {}

void MenuInputHandler::onResume() {}

void MenuInputHandler::onDestroy() {}
