#ifndef MENU_INPUT_HANDLER
#define MENU_INPUT_HANDLER

#include "Util.hpp"
#include "BaseInputHandler.hpp"

class MainMenu;

class MenuInputHandler : public BaseInputHandler {
public:
	MenuInputHandler(Game *);
	~MenuInputHandler();
	 
	void onDraw(SDL_Renderer *) override;
	void onUpdate() override;
	void onReset() override;

protected:
    void onBackPressed() override;
    void onTap(int, int) override;
    void onSwipe(Direction) override;
    void onTouchAndHold(int, int) override;
    void onPause() override;
    void onResume() override;
    void onDestroy() override;

private:
	MainMenu *menu;
};

#endif
