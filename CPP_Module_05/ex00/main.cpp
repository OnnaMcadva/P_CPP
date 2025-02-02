#include "Bureaucrat.hpp"
#include <iostream>

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << COLOR_BLUE << bob << COLOR_RESET << std::endl;

        bob.incrementGrade();
        std::cout << COLOR_BLUE << bob << COLOR_RESET << std::endl;

        bob.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 150);
        std::cout << COLOR_CYAN << alice << COLOR_RESET << std::endl;

        alice.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
