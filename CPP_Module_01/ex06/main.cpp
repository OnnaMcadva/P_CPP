#include "Harl.hpp"

 // the ex06: there was no switch statement sadly

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <log level>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(argv[1]);

    return 0;
}
