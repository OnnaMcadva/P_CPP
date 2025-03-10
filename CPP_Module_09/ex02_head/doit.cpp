#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

void readFromFile(const std::string& filename, std::deque<int>& deq, std::vector<int>& vec) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw std::runtime_error("Error: Unable to open file for reading.");
    }

    std::string line;

    if (std::getline(inFile, line)) {
        std::stringstream ss(line);
        int num;
        while (ss >> num) {
            deq.push_back(num);
        }
    }

    if (std::getline(inFile, line)) {
        std::stringstream ss(line);
        int num;
        while (ss >> num) {
            vec.push_back(num);
        }
    }

    inFile.close();
}

template <typename T>
void checkSorting(const T& originalContainer, const std::string& containerType) {
    T containerCopy = originalContainer;

    std::sort(containerCopy.begin(), containerCopy.end());

    bool isSorted = (containerCopy == originalContainer);

    std::cout << "Checking the " << containerType << " (after sorting):\n";
    if (isSorted) {
        std::cout << containerType << " was sorted correctly: Yeah, dude! 🎉 We did it! ✨\n";
    } else {
        std::cout << containerType << " was sorted correctly: No. 🔥 Burn in hell, klutz 👿\n";
    }
}

int main() {
    std::deque<int> deq;
    std::vector<int> vec;

    try {
        readFromFile("sorted_output.txt", deq, vec);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    checkSorting(deq, "💎Deque sorting");

    checkSorting(vec, "🦋Vector sorting");

    return 0;
}
