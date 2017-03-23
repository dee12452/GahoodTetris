#include "BaseInputHandler.hpp"

BaseInputHandler::BaseInputHandler() {}

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
			onKeyDown();
		case SDL_KEYUP:
			onKeyUp();
		default:
			break;
		}
	}
	for (int i = 0; i < scanCodesLength; i++) {
		if (keyboardState[desiredScanCodes[i]]) {
			onKeyHeld(desiredScanCodes[i]);
		}
	}
}