#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Util.hpp"

class InputHandler;
class Timer;

class Window {
public:
	Window(InputHandler *);
	Window(InputHandler *, float);
	~Window();
	void start();
	bool isRendering();

private:
	//For SDL rendering to screen
	SDL_Window *window;
	SDL_Texture *windowTexture;
	SDL_Renderer *windowRenderer;
	void renderToScreen();

	//For the window thread
	std::thread thread;
	void render();
	bool rendering;
	InputHandler *eventHandler;

	//For fps handling
	int fps;
	Timer *timer;
};

#endif