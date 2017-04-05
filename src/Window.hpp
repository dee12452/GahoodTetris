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
	void start();
	bool isRendering();
	int getWindowWidth() const;
	int getWindowHeight() const;
	void setInputHandler(BaseInputHandler *);

private:
	int windowWidth;
	int windowHeight;

	//For SDL rendering to screen
	SDL_Window *window;
	SDL_Texture *windowTexture;
	SDL_Renderer *windowRenderer;
	void renderToScreen();

	//For the window thread
	std::thread thread;
	void init();
	void close();
	void render();
	bool rendering;
	BaseInputHandler *eventHandler;

	//For fps handling
	int fps;
	Timer *timer;
};

#endif
