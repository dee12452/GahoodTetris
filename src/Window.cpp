#include "Window.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"
#include "Timer.hpp"
#include "DisplayUtil.hpp"
#include "TetrisGrid.hpp"

Window::Window(InputHandler *input) {
	windowWidth = DESIRED_WINDOW_WIDTH;
	windowHeight = DESIRED_WINDOW_HEIGHT;
	DisplayUtil::initScreen(windowWidth, windowHeight);
	rendering = true;
	eventHandler = input;
	fps = DEFAULT_FPS;
	timer = new Timer(fps);
}

Window::Window(InputHandler *input, int targetFPS) : Window(input) {
	fps = targetFPS;
	timer->setTargetTimeFPS(fps);
}

Window::~Window() {
	thread.join();
	eventHandler = NULL;
	if (timer != NULL) {
		delete timer;
		timer = NULL;
	}
}

void Window::render() {
	init();
	bool isRendering = true;
	while (isRendering) {
		SDL_Delay(CPU_USAGE_EVENT_DELAY);
		if (eventHandler != NULL) {
			eventHandler->pollEvents(DEFAULT_SCAN_KEYS, DEFAULT_SCAN_KEYS_SIZE);
			switch (eventHandler->getGame()->getGameState())
			{
			case PLAY:				
                if (timer->check()) {
					renderToScreen();
				}
				break;
			case EXIT:
				isRendering = false;
				break;
			default:
				break;
			}
		}
	}
	close();
	rendering = false;
}

void Window::start() {
	thread = std::thread(&Window::render, this);
}

bool Window::isRendering() {
	return rendering;
}

void Window::renderToScreen() {
    SDL_RenderClear(windowRenderer);
	SDL_RenderCopy(windowRenderer, windowTexture, NULL, NULL);
	eventHandler->getGame()->getTetrisGrid()->draw(windowRenderer, windowTexture);
	SDL_RenderPresent(windowRenderer);
}

int Window::getWindowWidth() const { return windowWidth; }
int Window::getWindowHeight() const { return windowHeight; }

void Window::init() {
	window = SDL_CreateWindow("title",
		DisplayUtil::getScreenWidth() / 2 - windowWidth / 2,
		DisplayUtil::getScreenHeight() / 2 - windowHeight / 2,
		windowWidth,
		windowHeight,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (window == NULL)
		Util::fatalSDLError("Failed to create the window");

	windowRenderer = SDL_CreateRenderer(window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (windowRenderer == NULL)
		Util::fatalSDLError("Failed to create window renderer");
	SDL_SetRenderDrawColor(windowRenderer, 0, 0, 0, 255);

	windowTexture = SDL_CreateTexture(windowRenderer,
		SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET,
		windowWidth,
		windowHeight);
	if (windowTexture == NULL)
		Util::fatalSDLError("Failed to create window texture");

	if (eventHandler != NULL && eventHandler->getGame() != NULL) {
		eventHandler->getGame()->createTetrisGrid(windowRenderer);
	}
	else {
		Util::fatalError("Could not instantiate the event handler");
	}

    renderToScreen();
}

void Window::close() {
	if (windowTexture != NULL) {
		SDL_DestroyTexture(windowTexture);
		windowTexture = NULL;
	}
	if (windowRenderer != NULL) {
		SDL_DestroyRenderer(windowRenderer);
		windowRenderer = NULL;
	}
	if (window != NULL) {
		SDL_DestroyWindow(window);
		window = NULL;
	}
}
