#ifndef UTIL_HPP
#define UTIL_HPP

#include "Const.hpp"
#include <android/log.h>

#define APP_NAME "Gahood Tetris"

class Sprite;

class Util {
private:
	Util() {}
	~Util() {}
	const static std::string TAG;
    static std::string assetsFolder;
	const static int PIECE_ROWS;
	const static int PIECE_COLUMNS;

public:
	static void androidPrint(const std::string &);
    static void print(const std::string &);
	static void printError(const std::string &);
	static void fatalError(const std::string &);
	static void fatalSDLError(const std::string &);

	static void createTetrisPiece(Uint8 **&);
	static void destroyTetrisPiece(Uint8 **&);
	static void rotateTetrisPiece(Direction, Uint8 **&);

	static bool parseLineForAnimationInformation(const std::string &, std::vector<int *> &);

	static int getRandomNumber(int, int);
    static void loadAndroidAssetFolder(const std::string &);
};

#endif
