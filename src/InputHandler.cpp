#include "InputHandler.hpp"

InputHandler::InputHandler() {}

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
	std::cout << "Quitter!" << std::endl;
}
