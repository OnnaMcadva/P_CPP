#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>

void ScalarConverter::convert(const std::string& literal) {

    char c = 0;
    int intValue = 0;
    float floatValue = 0.0f;
    double doubleValue = 0.0;

    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff") {
        std::cout << "\033[33mchar:\033[0m impossible" << std::endl;
        std::cout << "\033[34mint:\033[0m impossible" << std::endl;
        if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
            std::cout << "\033[35mfloat:\033[0m " << literal << std::endl;
            std::cout << "\033[36mdouble:\033[0m " << literal.substr(0, literal.length() - 1) << std::endl;
        } else {
            std::cout << "\033[35mfloat:\033[0m " << literal << "f" << std::endl;
            std::cout << "\033[36mdouble:\033[0m " << literal << std::endl;
        }
        return;
    }

    if (literal.length() == 1 && !isdigit(literal[0])) {
        c = literal[0];
        std::cout << "\033[33mchar:\033[0m '" << c << "'" << std::endl;
        std::cout << "\033[34mint:\033[0m " << static_cast<int>(c) << std::endl;
        std::cout << "\033[35mfloat:\033[0m " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "\033[36mdouble:\033[0m " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    char* endPtr;
    long int longValue = strtol(literal.c_str(), &endPtr, 10);
    if (*endPtr == '\0') {
        intValue = static_cast<int>(longValue);
        if (longValue < std::numeric_limits<char>::min() || longValue > std::numeric_limits<char>::max()) {
            std::cout << "\033[33mchar:\033[0m impossible" << std::endl;
        } else if (longValue < 32 || longValue > 126) {
            std::cout << "\033[33mchar:\033[0m Non displayable" << std::endl;
        } else {
            std::cout << "\033[33mchar:\033[0m '" << static_cast<char>(longValue) << "'" << std::endl;
        }
        std::cout << "\033[34mint:\033[0m " << intValue << std::endl;
        std::cout << "\033[35mfloat:\033[0m " << static_cast<float>(intValue) << ".0f" << std::endl;
        std::cout << "\033[36mdouble:\033[0m " << static_cast<double>(intValue) << ".0" << std::endl;
        return;
    }

    if (literal[literal.length() - 1] == 'f') {
        floatValue = strtof(literal.c_str(), &endPtr);
        if (*endPtr == 'f') {

            if (floatValue != static_cast<int>(floatValue)) {
                std::cout << "\033[33mchar:\033[0m impossible" << std::endl;
            } else if (floatValue < std::numeric_limits<char>::min() || floatValue > std::numeric_limits<char>::max()) {
                std::cout << "\033[33mchar:\033[0m impossible" << std::endl;
            } else if (floatValue < 32 || floatValue > 126) {
                std::cout << "\033[33mchar:\033[0m Non displayable" << std::endl;
            } else {
                std::cout << "\033[33mchar:\033[0m '" << static_cast<char>(floatValue) << "'" << std::endl;
            }
            if (floatValue < std::numeric_limits<int>::min() || floatValue > std::numeric_limits<int>::max()) {
                std::cout << "\033[34mint:\033[0m impossible" << std::endl;
            } else {
                std::cout << "\033[34mint:\033[0m " << static_cast<int>(floatValue) << std::endl;
            }
            std::cout << "\033[35mfloat:\033[0m " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
            std::cout << "\033[36mdouble:\033[0m " << std::fixed << std::setprecision(1) << static_cast<double>(floatValue) << std::endl;
            return;
        }
    }

    doubleValue = strtod(literal.c_str(), &endPtr);
    if (*endPtr == '\0') {

        if (doubleValue != static_cast<int>(doubleValue)) {
            std::cout << "\033[33mchar:\033[0m impossible" << std::endl;
        } else if (doubleValue < std::numeric_limits<char>::min() || doubleValue > std::numeric_limits<char>::max()) {
            std::cout << "\033[33mchar:\033[0m impossible" << std::endl;
        } else if (doubleValue < 32 || doubleValue > 126) {
            std::cout << "\033[33mchar:\033[0m Non displayable" << std::endl;
        } else {
            std::cout << "\033[33mchar:\033[0m '" << static_cast<char>(doubleValue) << "'" << std::endl;
        }
        if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max()) {
            std::cout << "\033[34mint:\033[0m impossible" << std::endl;
        } else {
            std::cout << "\033[34mint:\033[0m " << static_cast<int>(doubleValue) << std::endl;
        }
        std::cout << "\033[35mfloat:\033[0m " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << "f" << std::endl;
        std::cout << "\033[36mdouble:\033[0m " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
        return;
    }

    std::cout << "\033[33mchar:\033[0m impossible" << std::endl;
    std::cout << "\033[34mint:\033[0m impossible" << std::endl;
    std::cout << "\033[35mfloat:\033[0m impossible" << std::endl;
    std::cout << "\033[36mdouble:\033[0m impossible" << std::endl;
}