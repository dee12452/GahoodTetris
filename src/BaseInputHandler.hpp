#ifndef BASE_INPUT_HANDLER_HPP
#define BASE_INPUT_HANDLER_HPP

#include "Util.hpp"
#include "Game.hpp"

class BaseDrawable;

class BaseInputHandler {
public:
	BaseInputHandler(Game *);
	virtual ~BaseInputHandler();

	virtual void pollEvents(const SDL_Scancode *desiredScanCodes, int scanCodesLength);

	GameState getCurrentGameState() const;
	std::vector<BaseDrawable *> getCurrentGameDrawables() const;
	void setGameState(GameState) const;
	void createGameDrawables() const;

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
