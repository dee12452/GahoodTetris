#include "Window.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"

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
            InputHandler *h = static_cast<InputHandler *> (eventHandler);
            if(h->getGame()->getGameState() == Game::EXIT) {
                break;
            }
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
