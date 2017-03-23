#include "Util.hpp"

const std::string Util::TAG = "Gahood Tetris : ";

void Util::print(const std::string &s) {
	std::cout << s << std::endl;
}

void Util::printError(const std::string &s) {
	std::cerr << s << std::endl;
}

void Util::fatalError(const std::string &s) {
	printError(s);
	exit(EXIT_FAILURE);
}

void Util::fatalSDLError(const std::string &s) {
	printError(SDL_GetError());
	fatalError(s);
}