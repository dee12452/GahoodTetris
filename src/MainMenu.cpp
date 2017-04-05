#include "MainMenu.hpp"
#include "Sprite.hpp"

const int MainMenu::BUTTON_Y = 350, MainMenu::BUTTON_WIDTH = 70, MainMenu::BUTTON_HEIGHT = 35;

MainMenu::MainMenu(SDL_Renderer *renderer) {
	
	//Instantiate the Sprites
	menuBG = new Sprite(renderer,
		"../res/tetris_block_empty.png", 
		true);
	playButton = new Sprite(renderer,
		"../res/play_button.png",
		true);
	exitButton = new Sprite(renderer,
		"../res/exit_button.png",
		true);
	selector = new Sprite(renderer,
		"../res/selector.png",
		true);

	//Set location and dimensions of the sprites
	menuBG->setWidth(DESIRED_WINDOW_WIDTH);
	menuBG->setHeight(DESIRED_WINDOW_HEIGHT);

	playButton->setLocationX(BUTTON_WIDTH);
	playButton->setLocationY(BUTTON_Y);
	playButton->setWidth(BUTTON_WIDTH);
	playButton->setHeight(BUTTON_HEIGHT);

	exitButton->setLocationX(BUTTON_WIDTH * 3);
	exitButton->setLocationY(BUTTON_Y);
	exitButton->setWidth(BUTTON_WIDTH);
	exitButton->setHeight(BUTTON_HEIGHT);

	selector->setLocationX(0);
	selector->setLocationY(BUTTON_Y);
	selector->setWidth(BUTTON_WIDTH);
	selector->setHeight(BUTTON_HEIGHT);

	shouldExit = false;
}

MainMenu::~MainMenu() {
	if (menuBG != NULL) {
		delete menuBG;
		menuBG = NULL;
	}
	if (playButton != NULL) {
		delete playButton;
		playButton = NULL;
	}
	if (exitButton != NULL) {
		delete exitButton;
		exitButton = NULL;
	}
	if (selector != NULL) {
		delete selector;
		selector = NULL;
	}
}

void MainMenu::draw(SDL_Renderer *renderer) {
	menuBG->draw(renderer);
	playButton->draw(renderer);
	exitButton->draw(renderer);
	selector->draw(renderer);
}

void MainMenu::nextSelection() {
	if (shouldExit) {
		selector->setLocationX(0);
	}
	else {
		selector->setLocationX(BUTTON_WIDTH * 2);
	}
	shouldExit = !shouldExit;
}

void MainMenu::previousSelection() {
	nextSelection();
}