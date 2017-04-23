#include "../headers/AndroidUtil.hpp"

AndroidUtil::AndroidUtil() {}

AndroidUtil::~AndroidUtil() {}

std::vector<std::string> AndroidUtil::getAndroidTextFile(const std::string &fileName) {
    std::vector<std::string> strings;
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
