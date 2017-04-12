#include "AnimatorHelper.hpp"
#include "Timer.hpp"
#include "SpriteUtil.hpp"
#include <fstream>
#include <algorithm>

AnimatorHelper * AnimatorHelper::helper = NULL;

AnimatorHelper::AnimatorHelper() { 
	animating = false; 
	continueAnimating = false; 
	currentAnimationFile = ""; 
}

AnimatorHelper::~AnimatorHelper() { stopAnimation(); }

void AnimatorHelper::startAnimation(const std::string &file) {
	if (animating) { return; }
	currentAnimationFile = "../animation/" + file;
	animating = true;
	continueAnimating = true;
	thread = std::thread(&AnimatorHelper::beginAnimation, helper);
}

void AnimatorHelper::stopAnimation() {
	if (animating) {
		continueAnimating = false;
		thread.join();
		animating = false;
	}
}

AnimatorHelper * AnimatorHelper::getInstance() {
	if (helper == NULL) {
		helper = new AnimatorHelper();
	}
	return helper;
}

void AnimatorHelper::deleteInstance() {
	if (helper != NULL) {
		helper->stopAnimation();
		delete helper;
		helper = NULL;
	}
}

void AnimatorHelper::beginAnimation() {
	std::ifstream in;
	in.open(currentAnimationFile);
	std::string line;
	if (in.is_open() ) {
		while (std::getline(in, line)) {
			if (!parseLine(line))
				Util::fatalError("Error parsing animation file: " + currentAnimationFile);
		}
	}
	else {
		Util::fatalError("Fatal Error - Failed to open animation file: " + currentAnimationFile);
	}
	in.close();
	while (continueAnimating) {
		SDL_Delay(CPU_USAGE_ANIMATION_DELAY);
		bool allDone = true;
		for (size_t i = 0; i < animations.size(); i++) {
			//perform logic
			if (animations[i]->timerX->check()) {
				if (animations[i]->startX + animations[i]->offsetX != animations[i]->targetX) {
					if(animations[i]->startX < animations[i]->targetX)
						animations[i]->offsetX++;
					else
						animations[i]->offsetX--;
					allDone = false;
				}
			}
			if (animations[i]->timerY->check()) {
				if (animations[i]->startY + animations[i]->offsetY != animations[i]->targetY) {
					if(animations[i]->startY < animations[i]->targetY)
						animations[i]->offsetY++;
					else
						animations[i]->offsetY--;
					allDone = false;
				}
			}
			if (animations[i]->startX + animations[i]->offsetX != animations[i]->targetX || 
				animations[i]->startY + animations[i]->offsetY != animations[i]->targetY) {
				allDone = false;
			}
		}
		if (allDone) {
			continueAnimating = false;
		}
	}
	for (int i = animations.size() - 1; i >= 0; i--) {
		if (animations[i]->timerX != NULL) {
			delete animations[i]->timerX;
			animations[i]->timerX = NULL;
		}
		if (animations[i]->timerY != NULL) {
			delete animations[i]->timerY;
			animations[i]->timerY = NULL;
		}
		delete animations[i];
		animations[i] = NULL;
		animations.pop_back();
	}
}

void AnimatorHelper::draw(SDL_Renderer *renderer) {
	if (animating) {
		for (size_t i = 0; i < animations.size(); i++) {
			animations[i]->sprite->setLocationX(animations[i]->startX + animations[i]->offsetX);
			animations[i]->sprite->setLocationY(animations[i]->startY + animations[i]->offsetY);
			animations[i]->sprite->draw(renderer);
		}
	}
}

bool AnimatorHelper::parseLine(const std::string &line) {
	Animation *animation = new Animation();
	std::string command;
	int commandSize = 0;
	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			commandSize = i + 1;
			break;
		}
		command.push_back(line[i]);
	}
	if (command == "MOVE") {
		animation->type = MOVE;
		int startX = -1, startY = -1;
		int endX = -1, endY = -1;
		int startTime = -1, endTime = -1;
		int spriteId = -1;

		//get sprite id
		std::string info = "";
		for (size_t i = commandSize; i < line.length(); i++) {
			if (line[i] == ' ') {
				commandSize = i + 1;
				break;
			}
			info.push_back(line[i]);
		}
		spriteId = std::stoi(info);

		//get start x
		info = "";
		for (size_t i = commandSize; i < line.length(); i++) {
			if (line[i] == ' ') {
				commandSize = i + 1;
				break;
			}
			info.push_back(line[i]);
		}
		startX = std::stoi(info);

		//get start y
		info = "";
		for (size_t i = commandSize; i < line.length(); i++) {
			if (line[i] == ' ') {
				commandSize = i + 1;
				break;
			}
			info.push_back(line[i]);
		}
		startY = std::stoi(info);

		//get end x
		info = "";
		for (size_t i = commandSize; i < line.length(); i++) {
			if (line[i] == ' ') {
				commandSize = i + 1;
				break;
			}
			info.push_back(line[i]);
		}
		endX = std::stoi(info);

		//get end y
		info = "";
		for (size_t i = commandSize; i < line.length(); i++) {
			if (line[i] == ' ') {
				commandSize = i + 1;
				break;
			}
			info.push_back(line[i]);
		}
		endY = std::stoi(info);

		//get start time
		info = "";
		for (size_t i = commandSize; i < line.length(); i++) {
			if (line[i] == ' ') {
				commandSize = i + 1;
				break;
			}
			info.push_back(line[i]);
		}
		startTime = std::stoi(info);

		//get end time
		info = "";
		for (size_t i = commandSize; i < line.length(); i++) {
			if (line[i] == ' ') {
				commandSize = i + 1;
				break;
			}
			info.push_back(line[i]);
		}
		endTime = std::stoi(info);

		if (startTime >= 0 && endTime >= 0) {
			animation->startX = startX;
			animation->startY = startY;
			animation->offsetX = 0;
			animation->offsetY = 0;
			animation->targetX = endX;
			animation->targetY = endY;
			animation->timeStart = startTime;
			animation->duration = endTime;
			animation->timerX = new Timer(determineTimer(animation->startX - animation->targetX, animation->duration), false);
			animation->timerY = new Timer(determineTimer(animation->startY - animation->targetY, animation->duration), false);
			animation->done = false;
			Sprite *spr = SpriteUtil::getSprite(spriteId);
			if (spr != NULL) {
				animation->sprite = spr;
			}
			else {
				delete animation; animation = NULL; return false;
			}
			spr = NULL;
		}
		else {
			delete animation; animation = NULL; return false;
		}
	}
	//else if (command == "ROTATE") { animation->type = ROTATE; } //NOT AVAILABLE YET
	else { delete animation; animation = NULL; return false; }

	animations.push_back(animation);
	return true;
}

int AnimatorHelper::determineTimer(int distance, int duration) {
	return std::max(std::abs(duration / distance), 1);
}
