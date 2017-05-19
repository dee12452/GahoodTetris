#ifndef HOW_TO_PLAY_INPUT_HANDLER_HPP
#define HOW_TO_PLAY_INPUT_HANDLER_HPP

#include "BaseInputHandler.hpp"

class HowToPlayInputHandler : public BaseInputHandler {
public:
    HowToPlayInputHandler(Game *);
    ~HowToPlayInputHandler();
    void onReset() override;

protected:
    void onDraw(SDL_Renderer *) override;
    void onUpdate() override;
    void onKeyDown(SDL_Scancode) override;
    void onKeyHeld(SDL_Scancode) override;
    void onKeyUp(SDL_Scancode) override;
};

#endif
