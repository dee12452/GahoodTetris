#include "Player.hpp"
#include "SpriteUtil.hpp"

Player::Player() {
	resetPoints();
	name = "Test";
}

Player::Player(const std::string &n) : Player() {
	name = n;
}

Player::~Player() {
}

void Player::addPoints(int p) { points += p; }

void Player::addPoints(PieceTypes type) {
	switch (type)
	{
	case I:
		addPoints(2);
		break;
	case O:
		addPoints(3);
		break;
	case T:
		addPoints(5);
		break;
	case S:
		addPoints(7);
		break;
	case Z:
		addPoints(7);
		break;
	case L:
		addPoints(10);
		break;
	case J:
		addPoints(10);
		break;
	default:
		Util::fatalError("Added an invalid piece to player points!");
		break;
	}
}

void Player::resetPoints() { points = 0; }
void Player::setName(const std::string &n) { name = n; }

int Player::getPoints() const { return points; }
std::string Player::getName() const { return name; }

std::string Player::getPointsAsString() const {
	if (points == 0) return "0";
	std::string str = "";
	int tempPoints = points;
	while (tempPoints != 0) {
		str += (char)((tempPoints % 10) + '0');
		tempPoints /= 10;
	}
	for (size_t i = 0; i < str.length() / 2; i++) {
		char temp = str[i];
		str[i] = str[str.length() - i - 1];
		str[str.length() - i - 1] = temp;
	}
	return str;
}

void Player::draw(SDL_Renderer *renderer) {
	std::string pointsStr = getPointsAsString();
	int numbersSheetWidth = 690, numbersSheetHeight = 338;
	Sprite *numbers = SpriteUtil::getSprite(SpriteUtil::SPRITE_NUMBERS_SHEET);
	for (size_t i = 0; i < pointsStr.length(); i++) {
		int numChar = (int)pointsStr[i] - '0';
		SDL_Rect numbersRect;

		//5 numbers per row
		numbersRect.w = numbersSheetWidth / 5;
		
		//2 columns 
		numbersRect.h = numbersSheetHeight / 2;
		
		//4 is the largest number on 1st row
		if (numChar > 4) {
			numChar -= 5;
			numbersRect.y = numbersSheetHeight / 2;
		}
		else {
			numbersRect.y = 0;
		}
		numbersRect.x = numChar * numbersRect.w;

		SDL_Rect destinationRect;

		//Scale down the image, too big for 500 x 500
		destinationRect.w = numbersRect.w / 8;
		destinationRect.h = numbersRect.h / 8;
		destinationRect.x = PLAYER_SCORE_X + (i * destinationRect.w);
		destinationRect.y = PLAYER_SCORE_Y;
		numbers->setDimensions(destinationRect);

		numbers->draw(renderer, numbersRect);
	}
	numbers = NULL;
}