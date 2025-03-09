#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange exchange("data.csv");
    if (!exchange.isDatabaseLoaded()) {
        std::cerr << "Error: failed to load database." << std::endl;
        return 1;
    }

    exchange.processInput(argv[1]);

    return 0;
}
