#ifndef UTIL_HPP
#define UTIL_HPP

#include "Const.hpp"

class Util {
private:
	Util() {}
	~Util() {}
	const static std::string TAG;
	const static int PIECE_ROWS;
	const static int PIECE_COLUMNS;

public:
	static void print(const std::string &);
	static void printError(const std::string &);
	static void fatalError(const std::string &);
	static void fatalSDLError(const std::string &);

	static void createTetrisPiece(Uint8 **&, PieceTypes);
	static void destroyTetrisPiece(Uint8 **&);
	static void rotateTetrisPiece(Direction, Uint8 **&);
};

#endif