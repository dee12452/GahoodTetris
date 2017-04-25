#include "../headers/AndroidUtil.hpp"
#include "../headers/DisplayUtil.hpp"
#include "../headers/Sprite.hpp"
#include <sstream>
#include <string>

AndroidUtil::AndroidUtil() {}

AndroidUtil::~AndroidUtil() {}

std::vector<std::string> AndroidUtil::getAndroidTextFile(const std::string &fileName) {
    std::vector<std::string> strings;
    if(fileName.substr(0, 5) == "CLEAR") {
        Util::print("Setting up a clear animation...");
        strings.push_back(fileName);
        return strings;
    }
    SDL_RWops *in;
    in = SDL_RWFromFile(fileName.c_str(), "rt");
    if(in == NULL) {
        Util::fatalError("Failed to open Android asset: " + fileName);
    }
    const int maxChars = 25000;
    char buffer[maxChars];
    SDL_RWread(in, buffer, maxChars, maxChars);
    int i = 0;
    while(i < maxChars && buffer[i] != '\0') {
        std::string str = "";
        while(buffer[i] != '\0' && buffer[i] != '\n') {
            str += buffer[i];
            i++;
        }
        if(buffer[i] == '\0')
            break;
        strings.push_back(str);
        i++;
    }
    SDL_RWclose(in);
    return strings;
}

template<typename T>
std::string AndroidUtil::toString(T val) {
    std::ostringstream os;
    os << val;
    return os.str();
}

int AndroidUtil::getScreenStartX() { return 0; }

int AndroidUtil::getScreenStartY() {
    return (DisplayUtil::getScreenHeight() / 2 - DisplayUtil::getScreenWidth() / 2);
}

SDL_Rect AndroidUtil::getSpriteTouchRect(Sprite *spr) {
    SDL_Rect touchArea = spr->getRect();
    touchArea.x = AndroidUtil::getScreenStartX() + (touchArea.x * DisplayUtil::getScreenWidth()) / DESIRED_WINDOW_WIDTH;
    touchArea.y = AndroidUtil::getScreenStartY() + (touchArea.y * DisplayUtil::getScreenWidth()) / DESIRED_WINDOW_WIDTH;
    touchArea.w = (touchArea.w * DisplayUtil::getScreenWidth()) / DESIRED_WINDOW_WIDTH;
    touchArea.h = (touchArea.h * DisplayUtil::getScreenWidth()) / DESIRED_WINDOW_HEIGHT;
    return touchArea;
}

bool AndroidUtil::didTouchSprite(Sprite *spr, int touchX, int touchY) {
    SDL_Rect touchArea = AndroidUtil::getSpriteTouchRect(spr);
    if(touchX >= touchArea.x && touchX <= touchArea.x + touchArea.w) {
        if(touchY >= touchArea.y && touchY <= touchArea.y + touchArea.h) {
            return true;
        }
    }
    return false;
}

template std::string AndroidUtil::toString<int>(int);
template std::string AndroidUtil::toString<float>(float);
