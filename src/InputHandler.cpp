#include "InputHandler.hpp"
#include "Game.hpp"

InputHandler::InputHandler(Game *g) {
	game = g;
}

void InputHandler::onKeyDown() {

}

void InputHandler::onKeyHeld(SDL_Scancode key) {
	
}

void InputHandler::onKeyUp() {

}

void InputHandler::onQuitGame() {
	game->setGameState(Game::EXIT);
}

Game * InputHandler::getGame() const {
	return game;
}