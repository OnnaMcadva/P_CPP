#include "PmergeMe.hpp"
#include <cmath>
#include <deque>
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <algorithm>

int PmergeMe::comparisons_deq;

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {
        (void)other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        (void)other;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

/* 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
    10 923, 21 845, 43 691, 87 381, 174 763, 349 525, … */

long PmergeMe::jacobsthal_recipe(long n) {
    return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

// int formula_jacobsthal(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     int prev2 = 0;
//     int prev1 = 1;
//     int current;
//     for (int i = 2; i <= n + 1; i++) {
//         current = prev1 + 2 * prev2;
//         prev2 = prev1;
//         prev1 = current;
//     }
//     return current;
// }

std::deque<int>::iterator PmergeMe::moveIt(std::deque<int>::iterator it, int steps) {
    std::advance(it, steps);
    return it;
}

bool PmergeMe::compare_deq_iters(std::deque<int>::iterator left, std::deque<int>::iterator right) {
    comparisons_deq++;
    return *left < *right;
}

std::deque<std::deque<int>::iterator>::iterator PmergeMe::moveIt(std::deque<std::deque<int>::iterator>::iterator it, int steps) {
    std::advance(it, steps);
    return it;
}

void PmergeMe::swap_buns(std::deque<int>::iterator it, int bun_size) {
    std::deque<int>::iterator start = moveIt(it, -bun_size + 1);
    std::deque<int>::iterator end = moveIt(start, bun_size);
    while (start != end) {
        std::iter_swap(start, moveIt(start, bun_size));
        start++;
    }
}

int PmergeMe::get_jacobsthal_count(int k, int tray_size) {
    int prev = jacobsthal_recipe(k - 1);
    int curr = jacobsthal_recipe(k);
    int diff = curr - prev;
    return (diff > tray_size) ? tray_size : diff;
}

void PmergeMe::insert_from_tray(std::vector<int>& oven, std::vector<int>& tray, std::vector<int>::iterator& tray_it, 
    int baked_count, int& shift) { // Определяем границу для поиска (baked_count - shift)
    std::vector<int>::iterator oven_bound = oven.begin() + std::min(baked_count - shift, static_cast<int>(oven.size()));
    if (oven_bound < oven.begin()) {
        oven_bound = oven.begin();
    } else if (oven_bound > oven.end()) {
    oven_bound = oven.end();
    }

// Добавляем отладку перед поиском
    std::cout << "Preparing to insert " << *tray_it << " into oven, searching in range [";
    for (std::vector<int>::iterator it = oven.begin(); it != oven.end(); ++it) {
        if (it == oven_bound) {
            std::cout << "| "; // Отмечаем границу oven_bound
        }
        std::cout << *it << (it + 1 != oven.end() ? ", " : "");
    }
    std::cout << "]" << std::endl;

// Находим позицию для вставки с помощью upper_bound
    std::vector<int>::iterator index = std::upper_bound(oven.begin(), oven_bound, *tray_it);

// Добавляем отладку после поиска
    std::cout << "Found position for " << *tray_it << " at index " << (index - oven.begin()) << std::endl;

// Вставляем элемент из tray в oven
    std::vector<int>::iterator inserted = oven.insert(index, *tray_it);

// Выводим отладочное сообщение (оставляем как есть)
    std::cout << "Inserted element: " << *inserted << std::endl;

// Удаляем вставленный элемент из tray
    tray_it = tray.erase(tray_it);

// Если tray не пуст и tray_it не указывает на начало, отступаем на один назад
    if (tray_it != tray.begin() && !tray.empty()) {
        std::advance(tray_it, -1);
    }

// Обновляем shift, если вставка произошла на позиции baked_count
    shift += (inserted - oven.begin()) == baked_count;
}

void PmergeMe::insert_from_tray(std::deque<std::deque<int>::iterator>& oven, 
        std::deque<std::deque<int>::iterator>& tray, 
        std::deque<std::deque<int>::iterator>::iterator& tray_it, 
        int baked_count, int& shift) {
    int offset = baked_count - shift;
    std::deque<std::deque<int>::iterator>::iterator oven_bound;
    // Проверяем границы перед сдвигом
    if (offset < 0) {
        oven_bound = oven.begin();
    } else if (offset >= static_cast<int>(oven.size())) {
        oven_bound = oven.end();
    } else {
        oven_bound = moveIt(oven.begin(), offset);
    }
    std::deque<std::deque<int>::iterator>::iterator index = 
        std::upper_bound(oven.begin(), oven_bound, *tray_it, compare_deq_iters);
    std::deque<std::deque<int>::iterator>::iterator inserted = oven.insert(index, *tray_it);
    tray_it = tray.erase(tray_it);
    if (!tray.empty() && tray_it != tray.begin()) { 
        std::advance(tray_it, -1);
    } else if (!tray.empty()) {
        tray_it = tray.begin();
    }
    shift += (inserted - oven.begin()) == baked_count;
}

void PmergeMe::Ford_Johnson(std::vector<int>& vec, int bun_size) {
    typedef std::vector<int>::iterator VecIt;

    int bag_of_buns = vec.size() / bun_size;
    if (bag_of_buns < 2)
        return;

    bool is_odd = bag_of_buns % 2 == 1;

    std::cout << "\n ✨ Start ✨ \n" << std::endl;
    std::cout << "level: " << bun_size << ", bag_of_buns: " << bag_of_buns << std::endl;
    std::cout << "is_odd: " << is_odd << std::endl;


    VecIt start = vec.begin();
    VecIt finish = start;
    std::advance(finish, bun_size * bag_of_buns);
    VecIt dough = finish;

    std::cout << "start: " << *start << ", finish: beyond array (index " << bun_size * bag_of_buns 
    << "), dough: beyond array (index " << bun_size * bag_of_buns << ")" << std::endl;

    if (is_odd) {
        std::advance(dough, -bun_size);
    }

    std::cout << "Before pairs: ";
    for (VecIt it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    int batch_size = 2 * bun_size;
    for (VecIt it = start; it != dough; std::advance(it, batch_size)) {
        VecIt this_bun = it;
        VecIt next_bun = it;
        std::advance(this_bun, bun_size - 1);
        std::advance(next_bun, batch_size - 1);
        if (next_bun < vec.end()) {
            if (*next_bun < *this_bun) {
                for (int j = 0; j < bun_size; ++j) {
                    std::swap(*(it + j), *(it + bun_size + j));
                }
            }
        }
    }

    std::cout << "After pairs: ";
    for (VecIt it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    Ford_Johnson(vec, bun_size * 2);

    std::cout << "\n 🍕 Поехали 🍕 \n" << std::endl;

    std::vector<int> oven;
    std::vector<int> tray;

    oven.push_back(*(vec.begin() + (bun_size - 1)));
    oven.push_back(*(vec.begin() + (bun_size * 2 - 1)));

    for (int i = 4; i <= bag_of_buns; i += 2) {
        tray.push_back(*(vec.begin() + (bun_size * (i - 1) - 1)));
        oven.push_back(*(vec.begin() + (bun_size * i - 1)));
    }

    std::cout << "oven now: ";
    for (std::vector<int>::iterator it = oven.begin(); it != oven.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "tray now: ";
    for (std::vector<int>::iterator it = tray.begin(); it != tray.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    if (is_odd) {
        std::cout << "is_odd is true, processing odd bun with bun_size = " << bun_size << std::endl;
        std::vector<int>::iterator odd_bun_it = dough;
        std::advance(odd_bun_it, bun_size - 1);
        std::cout << "odd_bun_it points to index " << std::distance(vec.begin(), odd_bun_it) << std::endl;
        int odd_value = *odd_bun_it;
        std::cout << "odd_value from vec: " << odd_value << std::endl;
        tray.push_back(odd_value);
        std::cout << "odd bun is added to tray: " << odd_value << std::endl;
        std::cout << "Updated tray: ";
        for (std::vector<int>::iterator it = tray.begin(); it != tray.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    int baked_count = 0;
    for (int k = 2; k <= static_cast<int>(tray.size()) + 1; ++k) {
        int buns_to_bake = get_jacobsthal_count(k, tray.size());
        if (buns_to_bake == 0) break;
        std::cout << "Inserting " << buns_to_bake << " elements from tray to oven. Jacobsthal step: " << jacobsthal_recipe(k) << std::endl;
        std::cout << "Current tray size: " << tray.size() << ", oven size: " << oven.size() << std::endl;
        int shift = 0;
        std::vector<int>::iterator tray_it = tray.begin() + std::min(buns_to_bake - 1, static_cast<int>(tray.size()) - 1);
        std::cout << "tray_it points to: " << (tray_it != tray.end() ? *tray_it : 0) << " at index " << std::distance(tray.begin(), tray_it) << std::endl;
        for (int i = 0; i < buns_to_bake; ++i) {
            std::cout << "Inserting element at index " << std::distance(tray.begin(), tray_it) << " with value: " << (tray_it != tray.end() ? *tray_it : 0) << std::endl;
            insert_from_tray(oven, tray, tray_it, jacobsthal_recipe(k) + baked_count, shift);
            std::cout << "After insertion, oven: ";
            for (std::vector<int>::iterator it = oven.begin(); it != oven.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << "\nTray: ";
            for (std::vector<int>::iterator it = tray.begin(); it != tray.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
        baked_count += buns_to_bake;
        std::cout << "Updated baked_count: " << baked_count << std::endl;
    }

    for (size_t i = 0; i < tray.size(); i++) {
        std::cout << "Processing remaining element at index " << i << " in tray" << std::endl;
        std::vector<int>::iterator tray_bun = tray.begin() + i;
        std::cout << "tray_bun value: " << (tray_bun != tray.end() ? *tray_bun : 0) << std::endl;
        int oven_edge_idx = oven.size() - tray.size() + i + 1; // Исправлено +1
        std::cout << "Calculating oven_edge at index " << oven_edge_idx << std::endl;
        std::vector<int>::iterator oven_edge = oven.begin() + std::min(oven_edge_idx, static_cast<int>(oven.size()));
        std::cout << "oven_edge points to: " << (oven_edge != oven.end() ? *oven_edge : 0) << " at index " << std::distance(oven.begin(), oven_edge) << std::endl;
        std::vector<int>::iterator bake_spot = 
            std::upper_bound(oven.begin(), oven_edge, *tray_bun);
        std::cout << "bake_spot found at index " << std::distance(oven.begin(), bake_spot) << std::endl;
        oven.insert(bake_spot, *tray_bun);
        std::cout << "Inserted remaining element: " << *tray_bun << std::endl;
        std::cout << "Updated oven: ";
        for (std::vector<int>::iterator it = oven.begin(); it != oven.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> copy;
    copy.reserve(vec.size());
    for (std::vector<int>::iterator it = oven.begin(); it != oven.end(); ++it) {
        for (int i = 0; i < bun_size; i++) {
            // Предполагаем, что *it — это значение из vec, и нам нужно найти его индекс
            // Для простоты предположим, что мы можем найти индекс в vec, где значение совпадает с *it
            std::vector<int>::iterator bun_start = vec.begin();
            while (bun_start != vec.end() && *bun_start != *it) {
                ++bun_start;
            }
            if (bun_start == vec.end()) {
                std::cout << "Warning: Could not find value " << *it << " in vec for bun_start" << std::endl;
                continue;
            }
            // Сдвигаем bun_start на -bun_size + i + 1 относительно его позиции
            int offset = -bun_size + i + 1;
            std::vector<int>::iterator new_bun_start = bun_start + offset;
            if (new_bun_start < vec.begin() || new_bun_start >= vec.end()) {
                std::cout << "Warning: Offset " << offset << " out of bounds for vec size " << vec.size() << std::endl;
                continue;
            }
            copy.insert(copy.end(), *new_bun_start);
        }
    }

    std::vector<int>::iterator vec_it = vec.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    std::cout << "Starting copy back to vec, copy size: " << copy.size() << ", vec size: " << vec.size() << std::endl;
    while (copy_it != copy.end()) {
        if (vec_it == vec.end()) {
            std::cout << "Warning: vec_it out of bounds, copy_it remaining: " << std::distance(copy_it, copy.end()) << std::endl;
            break;
        }
        std::cout << "Copying value " << *copy_it << " from copy position " << std::distance(copy.begin(), copy_it) 
                  << " to vec position " << std::distance(vec.begin(), vec_it) << std::endl;
        *vec_it = *copy_it;
        ++vec_it;
        ++copy_it;
    }

    std::cout << "Final container: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Final vec size: " << vec.size() << std::endl;

    std::cout << "\n=== End sorting ===\n" << std::endl;
}

void PmergeMe::Ford_Johnson(std::deque<int>& deq, int bun_size) {
    typedef std::deque<int>::iterator DeqIt;

    int bag_of_buns = deq.size() / bun_size;
    if (bag_of_buns < 2)
        return;

    bool is_odd = bag_of_buns % 2 == 1;

    DeqIt start = deq.begin();
    DeqIt finish = moveIt(deq.begin(), bun_size * bag_of_buns);
    DeqIt dough = moveIt(finish, -(is_odd * bun_size));

    int batch_size = 2 * bun_size;
    for (DeqIt it = start; it != dough; std::advance(it, batch_size)) {
        DeqIt this_bun = moveIt(it, bun_size - 1);
        DeqIt next_bun = moveIt(it, bun_size * 2 - 1);
        comparisons_deq++;
        if (*this_bun > *next_bun) {
            swap_buns(this_bun, bun_size);
        }
    }

    Ford_Johnson(deq, bun_size * 2);

    std::deque<DeqIt> oven;
    std::deque<DeqIt> tray;

    oven.push_back(moveIt(deq.begin(), bun_size - 1));
    oven.push_back(moveIt(deq.begin(), bun_size * 2 - 1));

    for (int i = 4; i <= bag_of_buns; i += 2) {
        tray.push_back(moveIt(deq.begin(), bun_size * (i - 1) - 1));
        oven.push_back(moveIt(deq.begin(), bun_size * i - 1));
    }

    if (is_odd) {
        DeqIt odd_bun = moveIt(dough, bun_size - 1);
        tray.push_back(odd_bun);
    }

    int baked_count = 0;
    for (int k = 2; k <= static_cast<int>(tray.size()) + 1; ++k) {
        int buns_to_bake = get_jacobsthal_count(k, tray.size());
        if (buns_to_bake == 0) break;
        if (buns_to_bake > static_cast<int>(tray.size())) {
            buns_to_bake = tray.size();
        }
        int shift = 0;
        std::deque<DeqIt>::iterator tray_it = moveIt(tray.begin(), buns_to_bake - 1);
        for (int i = 0; i < buns_to_bake; ++i) {
            insert_from_tray(oven, tray, tray_it, jacobsthal_recipe(k) + baked_count, shift);
        }
        baked_count += buns_to_bake;
    }

    for (std::deque<int>::size_type i = 0; i < tray.size(); i++) {
        std::deque<DeqIt>::iterator tray_bun = moveIt(tray.begin(), i);
        std::deque<DeqIt>::iterator oven_edge = moveIt(oven.begin(), oven.size() - tray.size() + i + 1);
        std::deque<DeqIt>::iterator bake_spot = 
            std::upper_bound(oven.begin(), oven_edge, *tray_bun, compare_deq_iters);
        oven.insert(bake_spot, *tray_bun);
    }
    
    std::deque<int> copy;
    for (std::deque<DeqIt>::iterator it = oven.begin(); it != oven.end(); ++it) {
        for (int i = 0; i < bun_size; i++) {
            DeqIt bun_start = *it;
            std::advance(bun_start, -bun_size + i + 1);
            copy.push_back(*bun_start);
        }
    }
    
    DeqIt deq_it = deq.begin();
    std::deque<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end()) {
        *deq_it = *copy_it;
        deq_it++;
        copy_it++;
    }
}

double get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

void PmergeMe::merge_insertion_sort(std::vector<int>& vec, double& time_vec) {
    double start = get_current_time();
    Ford_Johnson(vec, 1);
    double end = get_current_time();
    time_vec = (end - start) * 1000000.0;
}

void PmergeMe::merge_insertion_sort(std::deque<int>& deq, double& time_deq) {
    double start = get_current_time();
    comparisons_deq = 0;
    Ford_Johnson(deq, 1);
    double end = get_current_time();
    time_deq = (end - start) * 1000000.0;
}
