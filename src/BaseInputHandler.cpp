#include "BaseInputHandler.hpp"
#include "Game.hpp"

BaseInputHandler::BaseInputHandler(Game *g) { this->game = g; }

BaseInputHandler::~BaseInputHandler() {}

void BaseInputHandler::pollEvents(const SDL_Scancode *desiredScanCodes, int scanCodesLength) {
	SDL_Event e;
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			onQuitGame();
			return;
		case SDL_KEYDOWN:
			onKeyDown(e.key.keysym.scancode);
		case SDL_KEYUP:
			onKeyUp(e.key.keysym.scancode);
		default:
			break;
		}
	}
	if (desiredScanCodes == NULL || scanCodesLength < 0)
		return;
	for (int i = 0; i < scanCodesLength; i++) {
		if (keyboardState[desiredScanCodes[i]]) {
			onKeyHeld(desiredScanCodes[i]);
		}
	}
}

Game * BaseInputHandler::getGame() const { return game; }
