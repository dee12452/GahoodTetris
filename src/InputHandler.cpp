#include "InputHandler.hpp"
#include "Game.hpp"

InputHandler::InputHandler(Game *g) : BaseInputHandler() {
    game = g;
}

InputHandler::~InputHandler() {}

void InputHandler::onKeyDown() {
	std::cout << "Key down!" << std::endl;
}

void InputHandler::onKeyHeld(SDL_Scancode) {
	std::cout << "Key Held!" << std::endl;
}

void InputHandler::onKeyUp() {
	std::cout << "Key up!" << std::endl;
}

void InputHandler::onQuitGame() {
    game->setGameState(Game::EXIT);
}

Game * InputHandler::getGame() const { return game; }
