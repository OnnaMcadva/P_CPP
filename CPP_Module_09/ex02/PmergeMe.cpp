#include "PmergeMe.hpp"

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

int PmergeMe::jacobsthal_modified(int n) {
    return jacobsthal(n + 2) - 1;
}

void PmergeMe::merge_insertion_sort(std::vector<int>& vec, double& time) {
    clock_t start = clock();
    ford_johnson_algorithm(vec);
    clock_t end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::merge_insertion_sort(std::deque<int>& deq, double& time) {
    clock_t start = clock();
    ford_johnson_algorithm(deq);
    clock_t end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::ford_johnson_algorithm(std::vector<int>& to_sort) {
    size_t size = to_sort.size();
    if (size <= 1) return;

    std::vector<int> main_sequence, sub_sequence;
    std::vector<int>::iterator it = to_sort.begin();

    while (it != to_sort.end()) {
        if (it + 1 != to_sort.end()) {
            if (*it < *(it + 1)) {
                main_sequence.push_back(*(it + 1));
                sub_sequence.push_back(*it);
            } else {
                main_sequence.push_back(*it);
                sub_sequence.push_back(*(it + 1));
            }
            it += 2;
        } else {
            sub_sequence.push_back(*it);
            break;
        }
    }

    ford_johnson_algorithm(main_sequence);

    for (size_t i = 0; i < sub_sequence.size(); ++i) {
        std::vector<int>::iterator insert_pos = std::lower_bound(
            main_sequence.begin(), main_sequence.end(), sub_sequence[i]
        );
        main_sequence.insert(insert_pos, sub_sequence[i]);
    }

    to_sort = main_sequence;
}

void PmergeMe::ford_johnson_algorithm(std::deque<int>& to_sort) {
    size_t size = to_sort.size();
    if (size <= 1) return;

    std::deque<int> main_sequence, sub_sequence;
    std::deque<int>::iterator it = to_sort.begin();

    while (it != to_sort.end()) {
        if (it + 1 != to_sort.end()) {
            if (*it < *(it + 1)) {
                main_sequence.push_back(*(it + 1));
                sub_sequence.push_back(*it);
            } else {
                main_sequence.push_back(*it);
                sub_sequence.push_back(*(it + 1));
            }
            it += 2;
        } else {
            sub_sequence.push_back(*it);
            break;
        }
    }

    ford_johnson_algorithm(main_sequence);

    for (size_t i = 0; i < sub_sequence.size(); ++i) {
        std::deque<int>::iterator insert_pos = std::lower_bound(
            main_sequence.begin(), main_sequence.end(), sub_sequence[i]
        );
        main_sequence.insert(insert_pos, sub_sequence[i]);
    }

    to_sort = main_sequence;
}