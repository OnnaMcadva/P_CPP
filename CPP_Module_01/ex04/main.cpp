#include "Sed.hpp"
#include <iostream>

#define DEF_COLOR "\033[0;39m"
#define GREEN "\033[0;92m"
#define RED "\033[0;91m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << RED << "Usage: " << argv[0] << " <filename> <s1> <s2>" << DEF_COLOR << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    std::cout << YELLOW << "Processing file: " << filename << DEF_COLOR << std::endl;
    if (!Sed::replace(filename, s1, s2)) {
        std::cerr << RED << "Error: Replacement failed!" << DEF_COLOR << std::endl;
        return 1;
    }

    std::cout << GREEN << "Replacement completed successfully. "
              << "Check the output file: " << filename << ".replace" << DEF_COLOR << std::endl;
    return 0;
}

/* echo "Hello world! world is great!" > test.txt
./Sed_is_for_losers test.txt world universe
cat test.txt.replace */