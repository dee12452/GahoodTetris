#include "../headers/AnimatorHelper.hpp"
#include "../headers/MoveAnimation.hpp"
#include "../headers/RowCompleteAnimation.hpp"
#include <fstream>
#include <sstream>

AnimatorHelper * AnimatorHelper::helper = NULL;

AnimatorHelper::AnimatorHelper() { 
	animating = false;
}

AnimatorHelper::~AnimatorHelper() {}

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

void AnimatorHelper::draw(SDL_Renderer *renderer) {
	bool allDone = true;
	for (size_t i = 0; i < animations.size(); i++) {
		animations[i]->animate(renderer);
		if (animations[i]->isAnimating())
			allDone = false;
	}
	//Might not need the below for now
	//if (allDone)
	//	stopAnimation();
}

void AnimatorHelper::startAnimation(const std::string &file) {
	if (!animating) {
		animating = true;
		parseAnimationFile(file);
		animationThread = std::thread(&AnimatorHelper::animate, this);
	}
}

void AnimatorHelper::stopAnimation() {
	if (animating) {
		animating = false;
		animationThread.join();
        for (size_t i = 0; i < animations.size(); i++) {
			delete animations[i];
			animations[i] = 0;
		}
		animations.clear();
	}
}

void AnimatorHelper::animate() {
	while (animating) {
		SDL_Delay(CPU_USAGE_ANIMATION_DELAY);
        for (size_t i = 0; i < animations.size(); i++) {
			animations[i]->update();
		}
	}
}

void AnimatorHelper::parseAnimationFile(const std::string &file) {
    std::ifstream in(file);
	if (!in.good()) {
		Util::fatalError("Error: could not find animation file: " + file);
	}
    bool deleteFile = false;
	std::string line;
	while (std::getline(in, line)) {
		std::istringstream stream(line);
		std::string command;
		int delay;
		
		//Get the command
		if (!(stream >> command)) {
			Util::fatalError("Error: animation file not correct format: " + file);
		}

		//Comment
		if (command.size() > 1 && command[0] == '/' && command[1] == '/') {
			continue;
		}

		//Get the delay
		if (!(stream >> delay)) {
			Util::fatalError("Error: animation file not correct format: " + file);
		}
		
		if (command == "MOVE") {
			animations.push_back(new MoveAnimation(delay, line));
		}
        else if(command == "CLEAR") {
            int x, y, rows;
            if(!(stream >> x >> y >> rows)) {
                Util::fatalError("Error: animation file not correct format: " + file);
            }
            SDL_Rect info;
            info.x = x; info.y = y;
            info.w = BLOCK_WIDTH; info.h = BLOCK_HEIGHT;
            animations.push_back(new RowCompleteAnimation(delay, info, rows));
            deleteFile = true;
            break;
        }
		else {
			Util::fatalError("Error: animation file not correct format (incorrect command): " + file);
		}
	}
    in.close();
    if(deleteFile) {
        std::remove(file.c_str());
    }
}

bool AnimatorHelper::isAnimating() const {
    if(animating) {
        bool continueAnimating = false;
		for (size_t i = 0; i < animations.size(); i++) {
			if(animations[i]->isAnimating())
                continueAnimating = true;
		}
        return continueAnimating;
    }
    else
        return false;
}

void AnimatorHelper::createClearAnimationFile(int x, int y, int rows) {
    std::remove(ANIMATION_CLEAR_ROW);
    std::ofstream out(ANIMATION_CLEAR_ROW);
    out << "CLEAR 0 " << x << " " << y << " " << rows;
    out.close();
}
