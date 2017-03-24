#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Util.hpp"

class InputHandler;
class Timer;

class Window {
public:
	Window(InputHandler *);
	Window(InputHandler *, int);
	~Window();
	void start();
	bool isRendering();
	int getWindowWidth() const;
	int getWindowHeight() const;

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
	InputHandler *eventHandler;

	//For fps handling
	int fps;
	Timer *timer;
};

#endif