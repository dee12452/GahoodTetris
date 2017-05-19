#ifndef BASE_INPUT_HANDLER_HPP
#define BASE_INPUT_HANDLER_HPP

#include "Util.hpp"
#include "Game.hpp"
#include "SpriteUtil.hpp"

class BaseDrawable;

class BaseInputHandler {
public:
	BaseInputHandler(Game *);
	virtual ~BaseInputHandler();

	virtual void pollEvents(const SDL_Scancode *desiredScanCodes, int scanCodesLength);
	virtual void onDraw(SDL_Renderer *) = 0;
	virtual void onUpdate() = 0;
	virtual void onReset() = 0;

	GameState getCurrentGameState() const;
	void setGameState(GameState) const;

protected:
	virtual void onKeyDown(SDL_Scancode) = 0;
	virtual void onKeyHeld(SDL_Scancode) = 0;
	virtual void onKeyUp(SDL_Scancode) = 0;
	virtual void onQuitGame();
	Game * getGame() const;

private:
	Game *game;
	bool gameCreated;
};

#endif
