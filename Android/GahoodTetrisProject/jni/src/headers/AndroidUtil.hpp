#ifndef ANDROID_UTIL_HPP
#define ANDROID_UTIL_HPP

#include "Util.hpp"

class Sprite;

class AndroidUtil {
public:
    static std::vector<std::string> getAndroidTextFile(const std::string &);

    template<typename T>
    static std::string toString(T);
    static int getScreenStartX();
    static int getScreenStartY();
    static bool didTouchSprite(Sprite *, int, int);

private:
    static SDL_Rect getSpriteTouchRect(Sprite *);
    AndroidUtil();
    ~AndroidUtil();
};

#endif
