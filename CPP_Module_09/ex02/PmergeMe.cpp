#include "PmergeMe.hpp"
#include <cmath>

int PmergeMe::comparisons_vec = 0;
int PmergeMe::comparisons_deq = 0;

size_t binarySearch(const std::vector<int>& vec, int value, int& comparisons) {
    size_t low = 0;
    size_t high = vec.size();
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        ++comparisons; // Увеличиваем счётчик сравнений
        if (vec[mid] < value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

int PmergeMe::jacobsthal_modified(int n) {
    return jacobsthal(n + 2) - 1;
}

void PmergeMe::merge_insertion_sort(std::vector<int>& vec, double& time) {
    comparisons_vec = 0;
    clock_t start = clock();
    ford_johnson_algorithm(vec);
    clock_t end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

void PmergeMe::merge_insertion_sort(std::deque<int>& deq, double& time) {
    comparisons_deq = 0;
    clock_t start = clock();
    ford_johnson_algorithm(deq);
    clock_t end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

// void PmergeMe::ford_johnson_algorithm(std::vector<int>& to_sort) {
//     size_t size = to_sort.size();
//     if (size <= 1) return;

//     std::vector<int> main_sequence, sub_sequence;
//     std::vector<int>::iterator it = to_sort.begin();

//     while (it != to_sort.end()) {
//         if (it + 1 != to_sort.end()) {
//             comparisons_vec++;
//             if (*it < *(it + 1)) {
//                 main_sequence.push_back(*(it + 1));
//                 sub_sequence.push_back(*it);
//             } else {
//                 main_sequence.push_back(*it);
//                 sub_sequence.push_back(*(it + 1));
//             }
//             it += 2;
//         } else {
//             sub_sequence.push_back(*it);
//             break;
//         }
//     }

//     ford_johnson_algorithm(main_sequence);

//     for (size_t i = 0; i < sub_sequence.size(); ++i) {
//         comparisons_vec += std::distance(main_sequence.begin(),
//                                          std::lower_bound(main_sequence.begin(), main_sequence.end(), sub_sequence[i]));
//         std::vector<int>::iterator insert_pos = std::lower_bound(
//             main_sequence.begin(), main_sequence.end(), sub_sequence[i]
//         );
//         main_sequence.insert(insert_pos, sub_sequence[i]);
//     }

//     to_sort = main_sequence;
// }

void PmergeMe::ford_johnson_algorithm(std::vector<int>& to_sort) {
    size_t size = to_sort.size();
    if (size <= 1) return;

    std::vector<int> main_sequence, sub_sequence;
    std::vector<int>::iterator it = to_sort.begin();

    // Разделение на пары
    while (it != to_sort.end()) {
        if (it + 1 != to_sort.end()) {
            comparisons_vec++;
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

    // Рекурсивная сортировка main_sequence
    ford_johnson_algorithm(main_sequence);

    // Вставка элементов из sub_sequence
    for (size_t i = 0; i < sub_sequence.size(); ++i) {
        size_t pos = binarySearch(main_sequence, sub_sequence[i], comparisons_vec);
        main_sequence.insert(main_sequence.begin() + pos, sub_sequence[i]);
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
            comparisons_deq++;
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
        comparisons_deq += std::distance(main_sequence.begin(),
                                         std::lower_bound(main_sequence.begin(), main_sequence.end(), sub_sequence[i]));
        std::deque<int>::iterator insert_pos = std::lower_bound(
            main_sequence.begin(), main_sequence.end(), sub_sequence[i]
        );
        main_sequence.insert(insert_pos, sub_sequence[i]);
    }

    to_sort = main_sequence;
}