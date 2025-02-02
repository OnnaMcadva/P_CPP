#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("test.txt");
    std::string line;

    while (std::getline(inputFile, line)) {
        std::cout << "Считанная строка: " << line << std::endl;
    }

    inputFile.close();
    return 0;
}
