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
    void onBackPressed() override;
    void onTouch(int, int) override;
    void onTouchAndHold(int, int) override;
    void onSwipe(Direction) override;
    void onPause() override;
    void onResume() override;
    void onDestroy() override;

private:
	BaseDrawable *tetrisGrid;
};

#endif
