#ifndef BASE_INPUT_HANDLER_HPP
#define BASE_INPUT_HANDLER_HPP

#include "Util.hpp"
#include "Game.hpp"
#include "SpriteUtil.hpp"

class BaseDrawable;
class Timer;

class BaseInputHandler {
public:
	BaseInputHandler(Game *);
	virtual ~BaseInputHandler();

    void update();
    void draw(SDL_Renderer *);
	virtual void pollEvents();
	virtual void onReset() = 0;

	GameState getCurrentGameState() const;
	void setGameState(GameState) const;

protected:
	virtual void onDraw(SDL_Renderer *) = 0;
	virtual void onUpdate() = 0;
    virtual void onBackPressed() = 0;
	virtual void onTouch(const SDL_TouchFingerEvent &) = 0;
    virtual void onTouchUp(const SDL_TouchFingerEvent &) = 0;
    virtual void onFingerMotion(const SDL_TouchFingerEvent &) = 0;
    virtual void onPause() = 0;
    virtual void onResume() = 0;
    virtual void onDestroy() = 0;
    virtual void onQuitGame();
	Game * getGame() const;

private:
	Game *game;
    bool gameCreated;
    bool isPaused;
};

#endif
