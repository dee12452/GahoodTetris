#include "Window.hpp"
#include "Timer.hpp"
#include "DisplayUtil.hpp"
#include "BaseInputHandler.hpp"
#include "SpriteUtil.hpp"
#include "AnimatorHelper.hpp"

Window::Window() {
	windowWidth = DESIRED_WINDOW_WIDTH;
	windowHeight = DESIRED_WINDOW_HEIGHT;
	DisplayUtil::initScreen(windowWidth, windowHeight);
	rendering = false;
	eventHandler = NULL;
	fps = DEFAULT_FPS;
	timer = new Timer(fps, true);
}

Window::Window(int targetFPS) : Window() {
	fps = targetFPS;
	timer->setTargetMilliseconds(fps, true);
}

Window::~Window() {
	thread.join();
	SpriteUtil::deleteSprites();
	if (timer != NULL) {
		delete timer;
		timer = NULL;
	}
}

void Window::render() {
	init();
	bool windowRunning = true;
	rendering = true;
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
	}
	close();
	rendering = false;
}

void Window::start() {
	thread = std::thread(&Window::render, this);
	
	//Wait for the window to initialize so it can load the sprites
	Util::print("Loading window...");
	while (!rendering) { SDL_Delay(CPU_USAGE_LOGIC_DELAY); }
	Util::print("Done loading window!");
}

bool Window::isRendering() const {
	return rendering;
}

void Window::renderToScreen() {
    SDL_RenderClear(windowRenderer);
	SDL_RenderCopy(windowRenderer, windowTexture, NULL, NULL);
	SDL_SetRenderTarget(windowRenderer, windowTexture);
	eventHandler->onDraw(windowRenderer);
	AnimatorHelper::getInstance()->draw(windowRenderer);
	SDL_SetRenderTarget(windowRenderer, NULL);
	SDL_RenderPresent(windowRenderer);
}

int Window::getWindowWidth() const { return windowWidth; }
int Window::getWindowHeight() const { return windowHeight; }

void Window::init() {
	window = SDL_CreateWindow(GAME_NAME,
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
	eventHandler = input;
}
