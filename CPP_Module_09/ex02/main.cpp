#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <set>
#include <fstream>
#include "PmergeMe.hpp"

void printSequence(const std::vector<int>& vec, size_t maxElements = 15) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i >= maxElements && vec.size() > maxElements) {
            std::cout << "[...]";
            break;
        }
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

bool hasDuplicates(const std::vector<int>& vec) {
    std::set<int> uniqueElements(vec.begin(), vec.end());
    return uniqueElements.size() != vec.size();
}

void writeToFile(const std::vector<int>& notSorted, const std::vector<int>& sorted, const std::string& filename) {
    std::ofstream outFile(filename.c_str(), std::ofstream::trunc);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    for (size_t i = 0; i < notSorted.size(); ++i) {
        outFile << notSorted[i] << (i == notSorted.size() - 1 ? "\n" : " ");
    }

    for (size_t i = 0; i < sorted.size(); ++i) {
        outFile << sorted[i] << (i == sorted.size() - 1 ? "\n" : " ");
    }

    outFile.close();
}

int calculateTheoreticalComparisons(int n) {
    int sum = 0;

    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        if (value < 1.0) {
            sum += 0;
        } else {
            double logValue = log(value) / log(2);
            int ceilLogValue = static_cast<int>(ceil(logValue));
            sum += ceilLogValue;
        }
    }

    return sum;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        int num;
        if (!(ss >> num) || num < 0) {
            std::cerr << "Error: Invalid input." << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    if (hasDuplicates(vec)) {
        std::cerr << "Error: Duplicates are not allowed." << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    printSequence(vec);

    double time_vec, time_deq;
    PmergeMe::merge_insertion_sort(vec, time_vec);
    PmergeMe::merge_insertion_sort(deq, time_deq);

    std::cout << "After: ";
    printSequence(vec);
    std::cout << "\n";

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::🦋vector: " << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::💎deque: " << time_deq << " us\n" << std::endl;

    std::cout << "Comparisons for std::🦋vector: " << PmergeMe::comparisons_vec << std::endl;
    std::cout << "Comparisons for std::💎deque: " << PmergeMe::comparisons_deq << std::endl;

    int theoreticalComparisons = calculateTheoreticalComparisons(vec.size());
    std::cout << "\33[33mTheoretical comparisons (Knuth's formula): \33[0m" << theoreticalComparisons << std::endl;

    writeToFile(std::vector<int>(deq.begin(), deq.end()), vec, "sorted_output.txt");

    return 0;
}

/* valgrind ./PmergeMe `shuf -i 1-100 -n $RANDOM | tr "\n" " "` */
/* ./PmergeMe `shuf -i 1-100 -n 21 | tr "\n" " "` */