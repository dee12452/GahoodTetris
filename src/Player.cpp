#include "Player.hpp"

Player::Player() {
	resetPoints();
	name = "Test";
}

Player::Player(const std::string &n) : Player() {
	name = n;
}
Player::~Player() {}

void Player::addPoints(int p) { points += p; }
void Player::resetPoints() { points = 0; }
void Player::setName(const std::string &n) { name = n; }

int Player::getPoints(int) const { return points; }
std::string Player::getName() const { return name; }