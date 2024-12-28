#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Testing with DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "Testing with INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "Testing with WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "Testing with ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "Testing with an unknown level:" << std::endl;
    harl.complain("NOT_A_LEVEL");
    return 0;
}
