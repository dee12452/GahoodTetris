#include "DisplayUtil.hpp"
#include "Window.hpp"

int DisplayUtil::screenWidth;
int DisplayUtil::screenHeight;

DisplayUtil::DisplayUtil() {
	//Set to default values initially
	DisplayUtil::screenWidth = -1;
	DisplayUtil::screenHeight = -1;
}

const int DisplayUtil::CURRENT_SCREEN = 0;

void DisplayUtil::initScreen(int targetWidth, int targetHeight) {
	SDL_DisplayMode currentDisplay;
	if (SDL_GetCurrentDisplayMode(CURRENT_SCREEN, &currentDisplay) < 0) {
		Util::fatalSDLError("Failed to get current display settings");
	}
	DisplayUtil::screenWidth = currentDisplay.w;
	DisplayUtil::screenHeight = currentDisplay.h;
	if (DisplayUtil::screenWidth < targetWidth || DisplayUtil::screenHeight < targetHeight) {
		Util::fatalError("Error: Screen size not large enough for game");
	}
}

void DisplayUtil::updateWindowDimensions(SDL_Window *window, int w, int h) {
	SDL_SetWindowSize(window, w, h);
}

int DisplayUtil::getScreenHeight() {
	return screenHeight;
}

int DisplayUtil::getScreenWidth() {
	return screenWidth;
}