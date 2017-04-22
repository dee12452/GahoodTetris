#ifndef DISPLAY_UTIL_HPP
#define DISPLAY_UTIL_HPP

#include "Util.hpp"

class DisplayUtil {
private:
	DisplayUtil();
	~DisplayUtil() {}
	static int screenHeight;
	static int screenWidth;
	static const int CURRENT_SCREEN;

public:
	static void initScreen(int, int);
	static void updateWindowDimensions(SDL_Window *, int, int);
	static int getScreenHeight();
	static int getScreenWidth();
};

#endif