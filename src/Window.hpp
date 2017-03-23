#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "Const.hpp"

class BaseInputHandler;

class Window {
public:
	Window();
	~Window();
	void start();
	bool isRendering();
	void setOnInputHandler(BaseInputHandler *);

private:
	SDL_Window *window;
	std::thread thread;
	void render();
	bool rendering, shouldRender;
	BaseInputHandler *eventHandler;
};

#endif