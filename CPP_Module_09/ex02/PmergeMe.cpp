#include "PmergeMe.hpp"
#include <cmath>
#include <deque>
#include <sys/time.h>
#include <iostream>

int PmergeMe::comparisons_vec;
int PmergeMe::comparisons_deq;

/* 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
    10 923, 21 845, 43 691, 87 381, 174 763, 349 525, … */

long PmergeMe::jacobsthal_recipe(long n) {
    return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::swap_buns(std::vector<int>::iterator it, int bun_size) {
    std::vector<int>::iterator start = moveIt(it, -bun_size + 1);
    std::vector<int>::iterator end = moveIt(start, bun_size);
    while (start != end) {
        std::iter_swap(start, moveIt(start, bun_size));
        start++;
    }
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

void PmergeMe::insert_from_tray(std::vector<std::vector<int>::iterator>& oven, 
        std::vector<std::vector<int>::iterator>& tray, 
        std::vector<std::vector<int>::iterator>::iterator& tray_it, 
        int baked_count, int& shift) {
    std::vector<std::vector<int>::iterator>::iterator oven_bound = moveIt(oven.begin(), baked_count - shift);
    if (oven_bound < oven.begin() || oven_bound > oven.end()) {
    oven_bound = oven.end();
    }
    std::vector<std::vector<int>::iterator>::iterator index = 
    std::upper_bound(oven.begin(), oven_bound, *tray_it, ccompare_vec_iters);
    std::vector<std::vector<int>::iterator>::iterator inserted = oven.insert(index, *tray_it);
    tray_it = tray.erase(tray_it);
    if (tray_it != tray.begin() && !tray.empty()) { 
    std::advance(tray_it, -1);
    }
    shift += (inserted - oven.begin()) == baked_count;
}

void PmergeMe::insert_from_tray(std::deque<std::deque<int>::iterator>& oven, 
        std::deque<std::deque<int>::iterator>& tray, 
        std::deque<std::deque<int>::iterator>::iterator& tray_it, 
        int baked_count, int& shift) {
    std::deque<std::deque<int>::iterator>::iterator oven_bound = moveIt(oven.begin(), baked_count - shift);
    if (oven_bound < oven.begin() || oven_bound > oven.end()) {
    oven_bound = oven.end();
    }
    std::deque<std::deque<int>::iterator>::iterator index = 
    std::upper_bound(oven.begin(), oven_bound, *tray_it, compare_deq_iters);
    std::deque<std::deque<int>::iterator>::iterator inserted = oven.insert(index, *tray_it);
    tray_it = tray.erase(tray_it);
    if (tray_it != tray.begin() && !tray.empty()) { 
    std::advance(tray_it, -1);
    }
    shift += (inserted - oven.begin()) == baked_count;
}

void PmergeMe::Ford_Johnson(std::vector<int>& vec, int bun_size, int& compar) {
    typedef std::vector<int>::iterator VecIt;

    int bag_of_buns = vec.size() / bun_size;
    if (bag_of_buns < 2)
        return;

    bool is_odd = bag_of_buns % 2 == 1;

    VecIt start = vec.begin();
    VecIt finish = moveIt(vec.begin(), bun_size * bag_of_buns);
    VecIt dough = moveIt(finish, -(is_odd * bun_size));

    int batch_size = 2 * bun_size;
    for (VecIt it = start; it != dough; std::advance(it, batch_size)) {
        VecIt this_bun = moveIt(it, bun_size - 1);
        VecIt next_bun = moveIt(it, bun_size * 2 - 1);
        compar++;
        if (*this_bun > *next_bun) {
            swap_buns(this_bun, bun_size);
        }
    }

    Ford_Johnson(vec, bun_size * 2, compar);

    std::vector<VecIt> oven;
    std::vector<VecIt> tray;

    oven.insert(oven.end(), moveIt(vec.begin(), bun_size - 1));
    oven.insert(oven.end(), moveIt(vec.begin(), bun_size * 2 - 1));

    for (int i = 4; i <= bag_of_buns; i += 2) {
        tray.insert(tray.end(), moveIt(vec.begin(), bun_size * (i - 1) - 1));
        oven.insert(oven.end(), moveIt(vec.begin(), bun_size * i - 1));
    }

    if (is_odd) {
        VecIt odd_bun = moveIt(dough, bun_size - 1);
        tray.insert(tray.end(), odd_bun);
    }

    int baked_count = 0;
    for (int k = 2; k <= static_cast<int>(tray.size()) + 1; ++k) {
        int buns_to_bake = get_jacobsthal_count(k, tray.size());
        if (buns_to_bake == 0) break;
        int shift = 0;
        std::vector<VecIt>::iterator tray_it = moveIt(tray.begin(), buns_to_bake - 1);
        for (int i = 0; i < buns_to_bake; ++i) {
            insert_from_tray(oven, tray, tray_it, jacobsthal_recipe(k) + baked_count, shift);
        }
        baked_count += buns_to_bake;
    }

    for (size_t i = 0; i < tray.size(); i++) {
        std::vector<VecIt>::iterator tray_bun = moveIt(tray.begin(), i);
        std::vector<VecIt>::iterator oven_edge = moveIt(oven.begin(), oven.size() - tray.size() + i);
        std::vector<VecIt>::iterator bake_spot = 
            std::upper_bound(oven.begin(), oven_edge, *tray_bun, ccompare_vec_iters);
        oven.insert(bake_spot, *tray_bun);
    }

    std::vector<int> copy;
    copy.reserve(vec.size());
    for (std::vector<VecIt>::iterator it = oven.begin(); it != oven.end(); ++it) {
        for (int i = 0; i < bun_size; i++) {
            VecIt bun_start = *it;
            std::advance(bun_start, -bun_size + i + 1);
            copy.insert(copy.end(), *bun_start);
        }
    }

    VecIt vec_it = vec.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end()) {
        *vec_it = *copy_it;
        vec_it++;
        copy_it++;
    }
}

void PmergeMe::Ford_Johnson(std::deque<int>& deq, int bun_size, int& compar) {
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
        compar++;
        if (*this_bun > *next_bun) {
            swap_buns(this_bun, bun_size);
        }
    }

    Ford_Johnson(deq, bun_size * 2, compar);

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
        int shift = 0;
        std::deque<DeqIt>::iterator tray_it = moveIt(tray.begin(), buns_to_bake - 1);
        for (int i = 0; i < buns_to_bake; ++i) {
            insert_from_tray(oven, tray, tray_it, jacobsthal_recipe(k) + baked_count, shift);
        }
        baked_count += buns_to_bake;
    }

    for (size_t i = 0; i < tray.size(); i++) {
        std::deque<DeqIt>::iterator tray_bun = moveIt(tray.begin(), i);
        std::deque<DeqIt>::iterator oven_edge = moveIt(oven.begin(), oven.size() - tray.size() + i);
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
    comparisons_vec = 0;
    Ford_Johnson(vec, 1, comparisons_vec);
    double end = get_current_time();
    time_vec = (end - start) * 1000000.0;
}

void PmergeMe::merge_insertion_sort(std::deque<int>& deq, double& time_deq) {
    double start = get_current_time();
    comparisons_deq = 0;
    Ford_Johnson(deq, 1, comparisons_deq);
    double end = get_current_time();
    time_deq = (end - start) * 1000000.0;
}

