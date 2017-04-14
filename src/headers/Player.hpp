#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Player : public BaseDrawable {
public:
	Player();
	Player(const std::string &);
	~Player();

	void addPoints(PieceTypes type);
	void addPoints(int);
	
	void resetPoints();
	void setName(const std::string &);

	int getPoints() const;
	std::string getPointsAsString() const;
	std::string getName() const;

	void draw(SDL_Renderer *) override;

private:
	int points;
	std::string name;
};

#endif