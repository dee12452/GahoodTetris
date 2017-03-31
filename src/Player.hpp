#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Util.hpp"

class Player {
public:
	Player();
	Player(const std::string &);
	~Player();

	void addPoints(int);
	void resetPoints();
	void setName(const std::string &);

	int getPoints(int) const;
	std::string getName() const;


private:
	int points;
	std::string name;
};

#endif