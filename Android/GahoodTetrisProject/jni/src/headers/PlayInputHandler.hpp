#ifndef PLAY_INPUT_HANDLER_HPP
#define PLAY_INPUT_HANDLER_HPP

#include "Const.hpp"
#include "BaseInputHandler.hpp"

class BaseDrawable;

class PlayInputHandler : public BaseInputHandler {
public:
	PlayInputHandler(Game *);
	~PlayInputHandler();

	void onDraw(SDL_Renderer *) override;
	void onUpdate() override;
	void onReset() override;

protected:
	void onKeyDown(SDL_Scancode) override;
	void onKeyHeld(SDL_Scancode) override;
	void onKeyUp(SDL_Scancode) override;

private:
	BaseDrawable *tetrisGrid;
};

#endif
