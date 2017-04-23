#include "../headers/Util.hpp"
#include <random>
#include <sstream>

std::string Util::assetsFolder = "";
const std::string Util::TAG = "Gahood Tetris : ";
const int Util::PIECE_ROWS = 3;
const int Util::PIECE_COLUMNS = 3;

void Util::androidPrint(const std::string &s) {
    __android_log_print(ANDROID_LOG_VERBOSE, APP_NAME, "%s\n", s.c_str());
}

void Util::print(const std::string &s) {
	std::cout << s << std::endl;
    androidPrint(s);
}

void Util::printError(const std::string &s) {
	std::cerr << s << std::endl;
    androidPrint(s);
}

void Util::fatalError(const std::string &s) {
	printError(s);
	exit(EXIT_FAILURE);
}

void Util::fatalSDLError(const std::string &s) {
	printError(SDL_GetError());
	fatalError(s);
}

void Util::createTetrisPiece(Uint8 **&piece) {
	piece = new Uint8 *[Util::PIECE_ROWS];
	for (int i = 0; i < Util::PIECE_ROWS; i++) {
		piece[i] = new Uint8[Util::PIECE_COLUMNS];
		for (int j = 0; j < Util::PIECE_COLUMNS; j++) {
			piece[i][j] = 0;
		}
	}
	switch (Util::getRandomNumber(0, NUMBER_OF_PIECE_TYPES - 1)) {
	case I:
		piece[1][0] = 1;
		piece[1][1] = 1;
		piece[1][2] = 1;
		break;
	case O:
		piece[1][0] = 1;
		piece[0][0] = 1;
		piece[0][1] = 1;
		piece[1][1] = 1;
		break;
	case S:
		piece[2][0] = 1;
		piece[1][0] = 1;
		piece[1][1] = 1;
		piece[0][1] = 1;
		break;
	case Z:
		piece[0][0] = 1;
		piece[1][0] = 1;
		piece[1][1] = 1;
		piece[2][1] = 1;
		break;
	case T:
		piece[0][0] = 1;
		piece[0][1] = 1;
		piece[0][2] = 1;
		piece[1][1] = 1;
		break;
	}
}

void Util::destroyTetrisPiece(Uint8 **&piece) {
	for (int i = 0; i < Util::PIECE_ROWS; i++) {
		delete piece[i];
		piece[i] = NULL;
	}
	delete piece;
}

void Util::rotateTetrisPiece(Direction d, Uint8 **&piece) {
	switch (d)
	{
	case RIGHT:
		break;
	case LEFT:
		break;
	default:
		break;
	}
}

int Util::getRandomNumber(int min, int max) {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> distribution(min, max);
	return distribution(rng);
}

bool Util::parseLineForAnimationInformation(const std::string &line, std::vector<int *> &information) {
	int substrStart = 0;
	int count = 0;
	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			count++;
		}
		if (count == 2) {
			substrStart = static_cast<int> (i) + 1;
			break;
		}
	}
	std::string substring = line.substr(substrStart);
	std::istringstream stream(substring);

	for (size_t i = 0; i < information.size(); i++) {
		if (!(stream >> *information[i]))
			return false;
	}
	return true;
}

void Util::loadAndroidAssetFolder(const std::string &s) {
    assetsFolder = s;
}
