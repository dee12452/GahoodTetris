#ifndef PLAY_INPUT_HANDLER_HPP
#define PLAY_INPUT_HANDLER_HPP

#include "Const.hpp"
#include "BaseInputHandler.hpp"

class Timer;
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
    void onTouch(const SDL_TouchFingerEvent &) override;
    void onTouchUp(const SDL_TouchFingerEvent &) override;
    void onFingerMotion(const SDL_TouchFingerEvent &) override;
    void onPause() override;
    void onResume() override;
    void onDestroy() override;

private:
	BaseDrawable *tetrisGrid;
    Timer *touchTimer;
    bool swiped;
};

#endif
