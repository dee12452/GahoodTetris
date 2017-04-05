#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Util.hpp"
#include "BaseDrawable.hpp"

class Player : public BaseDrawable {
public:
	Player(SDL_Renderer *);
	Player(SDL_Renderer *, const std::string &);
	~Player();

	void addPoints(PieceTypes type);
	void addPoints(int);
	
	void resetPoints();
	void setName(const std::string &);

	int getPoints() const;
	std::string getPointsAsString() const;
	std::string getName() const;

	void draw(SDL_Renderer *);

private:
	SDL_Texture *numbersSheet;
	int points;
	std::string name;
};

#endif