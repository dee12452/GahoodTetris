#include "../headers/Window.hpp"
#include "../headers/Timer.hpp"
#include "../headers/DisplayUtil.hpp"
#include "../headers/BaseInputHandler.hpp"
#include "../headers/SpriteUtil.hpp"

Window::Window() {
	windowWidth = DESIRED_WINDOW_WIDTH;
	windowHeight = DESIRED_WINDOW_HEIGHT;
	DisplayUtil::initScreen(windowWidth, windowHeight);
	rendering = false, changeHandler = false, allowChangeHandler = false;
	eventHandler = NULL;
	fps = DEFAULT_FPS;
	timer = new Timer(fps, true);
	rendering = true;
}

Window::Window(int targetFPS) : Window() {
	fps = targetFPS;
	timer->setTargetMilliseconds(fps, true);
}

Window::~Window() {
	SpriteUtil::deleteSprites();
	if (timer != NULL) {
		delete timer;
		timer = NULL;
	}
	rendering = false;
}

void Window::render() {
	bool windowRunning = true;
    while (windowRunning) {
        SDL_Delay(CPU_USAGE_EVENT_DELAY);
		if (eventHandler != NULL) {
			eventHandler->pollEvents(DEFAULT_SCAN_KEYS, DEFAULT_SCAN_KEYS_SIZE);
			if (eventHandler->getCurrentGameState() == EXIT)
				windowRunning = false;
			else
				if (timer->check()) {
					renderToScreen();
				}
		}
		
		//Wait for the handler to change
		if (changeHandler) {
			allowChangeHandler = true;
			while (changeHandler) { SDL_Delay(CPU_USAGE_LOGIC_DELAY); }
		}
	}
}

void Window::start() {
    render();
	close();
}

bool Window::isRendering() const {
	return rendering;
}

void Window::renderToScreen() {
    SDL_RenderClear(windowRenderer);
	SDL_RenderCopy(windowRenderer, windowTexture, NULL, NULL);
	SDL_SetRenderTarget(windowRenderer, windowTexture);
	eventHandler->onDraw(windowRenderer);
	SDL_SetRenderTarget(windowRenderer, NULL);
	SDL_RenderPresent(windowRenderer);
}

int Window::getWindowWidth() const { return windowWidth; }
int Window::getWindowHeight() const { return windowHeight; }

void Window::init() {
	window = SDL_CreateWindow(GAME_NAME,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
	    windowWidth,
		windowHeight,
		SDL_WINDOW_OPENGL/* | SDL_WINDOW_RESIZABLE*/);
	if (window == NULL)
		Util::fatalSDLError("Failed to create the window");

	windowRenderer = SDL_CreateRenderer(window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (windowRenderer == NULL)
		Util::fatalSDLError("Failed to create window renderer");
	SDL_RenderSetLogicalSize(windowRenderer, windowWidth, windowHeight);
    SDL_SetRenderDrawColor(windowRenderer, 0, 0, 0, 255);

	SpriteUtil::createSprites(windowRenderer);

	windowTexture = SDL_CreateTexture(windowRenderer,
		SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET,
		windowWidth,
		windowHeight);
	if (windowTexture == NULL)
		Util::fatalSDLError("Failed to create window texture");
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

void Window::setInputHandler(BaseInputHandler *input) {
	//Request the lock, then wait for the lock to allow the change
	changeHandler = true;
	while (!allowChangeHandler) { SDL_Delay(CPU_USAGE_LOGIC_DELAY); }
	eventHandler = input;
}

void Window::releaseHandlerLock() {
	//Release the lock
	allowChangeHandler = false;
	changeHandler = false;
}
