#ifndef BASE_INPUT_HANDLER_HPP
#define BASE_INPUT_HANDLER_HPP

#include "Util.hpp"
#include "Game.hpp"

class BaseInputHandler {
public:
	BaseInputHandler(Game *);
	virtual ~BaseInputHandler();

	virtual void pollEvents(const SDL_Scancode *desiredScanCodes, int scanCodesLength);

	Game * getGame() const;

protected:
	virtual void onKeyDown(SDL_Scancode) = 0;
	virtual void onKeyHeld(SDL_Scancode) = 0;
	virtual void onKeyUp(SDL_Scancode) = 0;
	virtual void onQuitGame() = 0;

	Game *game;
};

#endif
