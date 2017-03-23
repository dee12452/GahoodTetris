#ifndef BASE_INPUT_HANDLER_HPP
#define BASE_INPUT_HANDLER_HPP

#include "Const.hpp"

class BaseInputHandler {
public:
	BaseInputHandler();
	virtual ~BaseInputHandler();

	virtual void pollEvents(const SDL_Scancode *desiredScanCodes, int scanCodesLength);

protected:
	virtual void onKeyDown() = 0;
	virtual void onKeyHeld(SDL_Scancode) = 0;
	virtual void onKeyUp() = 0;
	virtual void onQuitGame() = 0;
};

#endif
