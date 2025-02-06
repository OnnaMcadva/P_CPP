#include "ScalarConverter.hpp"
#include <iostream>

/* Be careful with numbers biiger than INT_MAX and smaller than INT_MIN in your following projects.  */

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}
