#include "Window.hpp"
#include "BaseInputHandler.hpp"

Window::Window() {
	rendering = true;
	shouldRender = true;
	eventHandler = NULL;
}

Window::~Window() {
	shouldRender = false;
	thread.join();
}

void Window::render() {
	window = SDL_CreateWindow("title", 100, 100, 500, 500, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	while (shouldRender) {
		if (eventHandler != NULL) {
			eventHandler->pollEvents(DEFAULT_SCAN_KEYS, DEFAULT_SCAN_KEYS_SIZE);
		}
	}
	if (window != NULL) {
		SDL_DestroyWindow(window);
		window = NULL;
	}
	rendering = false;
}

void Window::start() {
	thread = std::thread(&Window::render, this);
}

bool Window::isRendering() {
	return rendering;
}

void Window::setOnInputHandler(BaseInputHandler *handler) {
	eventHandler = handler;
}