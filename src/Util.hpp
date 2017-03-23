#ifndef UTIL_HPP
#define UTIL_HPP

#include "Const.hpp"

class Util {
private:
	Util() {}
	~Util() {}
	const static std::string TAG;

public:
	static void print(const std::string &);
	static void printError(const std::string &);
	static void fatalError(const std::string &);
	static void fatalSDLError(const std::string &);
};

#endif