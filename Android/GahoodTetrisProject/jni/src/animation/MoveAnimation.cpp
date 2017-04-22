#include "../headers/MoveAnimation.hpp"
#include "../headers/SpriteUtil.hpp"
#include <algorithm>

MoveAnimation::MoveAnimation(int delayMs, const std::string &line) : BaseAnimation(delayMs) {
	parseAnimation(line);
	offsetX = 0;
	offsetY = 0;
}

MoveAnimation::~MoveAnimation() {}

void MoveAnimation::onAnimate(SDL_Renderer *renderer) {
	int tempX = SpriteUtil::getSprite(spriteId)->getLocationX();
	int tempY = SpriteUtil::getSprite(spriteId)->getLocationY();
	SpriteUtil::getSprite(spriteId)->setLocationX(startX + offsetX);
	SpriteUtil::getSprite(spriteId)->setLocationY(startY + offsetY);
	SpriteUtil::getSprite(spriteId)->draw(renderer);
	SpriteUtil::getSprite(spriteId)->setLocationX(tempX);
	SpriteUtil::getSprite(spriteId)->setLocationY(tempY);
}

void MoveAnimation::parseAnimation(const std::string &line) {
	std::vector<int *> info;
	info.push_back(&spriteId);
	info.push_back(&startX);
	info.push_back(&startY);
	info.push_back(&finishX);
	info.push_back(&finishY);
	info.push_back(&time);
	info.push_back(&isInfinite);

	if (!Util::parseLineForAnimationInformation(line, info) || !SpriteUtil::getSprite(spriteId) || (isInfinite != 0 && isInfinite != 1)) {
		Util::fatalError("Error: Bad Move animation file format!");
	}

	info.clear();
	time = std::max(1, time);
	firstUpdate = true;
}

void MoveAnimation::onUpdate() {
	if (firstUpdate) {
		start = std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now().time_since_epoch());
		firstUpdate = false;
	}
	finish = std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now().time_since_epoch());
	double elapsedTime = static_cast<double> ((finish - start).count());
	double rateX = (double)(finishX - startX) / (double)(time);
	double rateY = (double)(finishY - startY) / (double)(time);
	if (startX + offsetX != finishX) {
		if (finishX > startX) {
			offsetX = std::min(static_cast<int> (elapsedTime * rateX), finishX - startX);
		}
		else {
			offsetX = std::max(static_cast<int> (elapsedTime * rateX), finishX - startX);
		}
	}
	if (startY + offsetY != finishY) {
		if (finishY > startY) {
			offsetY = std::min(static_cast<int> (elapsedTime * rateY), finishY - startY);
		}
		else {
			offsetY = std::max(static_cast<int> (elapsedTime * rateY), finishY - startY);
		}
	}
	if (isInfinite) {
		if (startY + offsetY == finishY && startX + offsetX == finishX) {
			reset();
			offsetX = 0;
			offsetY = 0;
			firstUpdate = true;
		}
	}
}

bool MoveAnimation::isAnimating() const {
	if (startX + offsetX == finishX && startY + offsetY == finishY)
		return false;
	return true;
}
