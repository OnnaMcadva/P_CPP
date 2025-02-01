#pragma once

#include <string>
#include <fstream>

class Sed {
public:
    static bool replace(const std::string& filename, const std::string& s1, const std::string& s2);
};
