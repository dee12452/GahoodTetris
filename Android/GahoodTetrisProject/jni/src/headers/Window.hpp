#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class BaseInputHandler;
class Timer;

class Window {
public:
	Window();
	Window(int);
	~Window();
	void init();
	void start();
	bool isRendering() const;
	int getWindowWidth() const;
	int getWindowHeight() const;
	void setInputHandler(BaseInputHandler *);
	void releaseHandlerLock();

private:
	int windowWidth;
	int windowHeight;

	//For SDL rendering to screen
	SDL_Window *window;
	SDL_Texture *windowTexture;
	SDL_Renderer *windowRenderer;
	void renderToScreen();

	//For the window thread
	void close();
	void render();
	bool rendering, changeHandler, allowChangeHandler;
	BaseInputHandler *eventHandler;

	//For fps handling
	int fps;
	Timer *timer;
};

#endif
