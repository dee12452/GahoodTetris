#ifndef PLAY_INPUT_HANDLER_HPP
#define PLAY_INPUT_HANDLER_HPP

#include "Const.hpp"
#include "BaseInputHandler.hpp"

class PlayInputHandler : public BaseInputHandler {
public:
	PlayInputHandler(Game *);
	~PlayInputHandler() {}

	void onDraw(SDL_Renderer *);
	void onUpdate();
	void onReset();

protected:
	void onKeyDown(SDL_Scancode);
	void onKeyHeld(SDL_Scancode);
	void onKeyUp(SDL_Scancode);
};

#endif
