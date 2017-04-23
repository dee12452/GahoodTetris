#ifndef ANDROID_UTIL_HPP
#define ANDROID_UTIL_HPP

#include "Util.hpp"
#include <istream>

class AndroidUtil {
public:
    static std::vector<std::string> getAndroidTextFile(const std::string &);

    template<typename T>
    static std::string toString(T);
private:
    AndroidUtil();
    ~AndroidUtil();
};

#endif
