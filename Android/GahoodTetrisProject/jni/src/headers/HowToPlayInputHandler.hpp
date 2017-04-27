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
    void onBackPressed() override;
    void onTouch(const SDL_TouchFingerEvent &) override;
    void onTouchUp(const SDL_TouchFingerEvent &) override;
    void onFingerMotion(const SDL_TouchFingerEvent &) override;
    void onPause() override;
    void onResume() override;
    void onDestroy() override;
};

#endif
