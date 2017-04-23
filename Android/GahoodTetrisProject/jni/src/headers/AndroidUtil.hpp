#ifndef ANDROID_UTIL_HPP
#define ANDROID_UTIL_HPP

#include "Util.hpp"
#include <istream>

class AndroidUtil {
public:
    static std::vector<std::string> getAndroidTextFile(const std::string &);
private:
    AndroidUtil();
    ~AndroidUtil();
};

#endif
