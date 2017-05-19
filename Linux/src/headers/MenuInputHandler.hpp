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
	void onKeyDown(SDL_Scancode) override;
	void onKeyHeld(SDL_Scancode) override;
	void onKeyUp(SDL_Scancode) override;

private:
	MainMenu *menu;
};

#endif