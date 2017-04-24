#include "../headers/AnimatorHelper.hpp"
#include "../headers/MoveAnimation.hpp"
#include "../headers/RowCompleteAnimation.hpp"
#include <sstream>
#include <fstream>

AnimatorHelper * AnimatorHelper::helper = NULL;

AnimatorHelper::AnimatorHelper() { 
	animating = false;
    updating = true;
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
	//bool allDone = true;
	for (size_t i = 0; i < animations.size(); i++) {
		animations[i]->animate(renderer);
		/*
        if (animations[i]->isAnimating())
	        allDone = false;
        */
	}
	//Might not need the below for now
	//if (allDone)
	//	stopAnimation();
}

void AnimatorHelper::startAnimation(const std::string &file) {
	if (!animating) {
        Util::print("*********************************************************");
        Util::print("*********************************************************");
        Util::print("*********************************************************");
        Util::print("Started Animation!");
        Util::print("*********************************************************");
        Util::print("*********************************************************");
        Util::print("*********************************************************");
		animating = true;
		parseAnimationFile(file);
		animationThread = std::thread(&AnimatorHelper::animate, this);
	}
}

void AnimatorHelper::pauseAnimation() {
    updating = false;
}

void AnimatorHelper::resumeAnimation() {
    updating = true;
}

void AnimatorHelper::stopAnimation() {
	if (animating) {
		animating = false;
		animationThread.join();
        Util::print("*********************************************************");
        Util::print("*********************************************************");
        Util::print("*********************************************************");
        Util::print("Stopped Animation!");
        Util::print("*********************************************************");
        Util::print("*********************************************************");
        Util::print("*********************************************************");
        Util::print("*********************************************************");
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
    std::vector<std::string> commands = AndroidUtil::getAndroidTextFile(file);
	for(size_t i = 0; i < commands.size(); i++) {
		std::istringstream stream(commands[i]);
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
			animations.push_back(new MoveAnimation(delay, commands[i]));
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
            break;
        }
		else {
			Util::fatalError("Error: animation file not correct format (incorrect command): " + file);
		}
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

std::string AnimatorHelper::createClearAnimation(int x, int y, int rows) {
    std::string ret = "CLEAR 0 ";
    ret += AndroidUtil::toString(x);
    ret += " ";
    ret += AndroidUtil::toString(y);
    ret += " ";
    ret += AndroidUtil::toString(rows);
    return ret;
}
