#pragma once

#include <algorithm>
#include <deque>
#include <vector>
#include <ctime>
#include <iostream>
#include <cmath>

class PmergeMe {
public:
    static void merge_insertion_sort(std::vector<int>& vec, double& time_vec);
    static void merge_insertion_sort(std::deque<int>& deq, double& time_deq);

    static int comparisons_vec;
    static int comparisons_deq;

private:
    template <typename T>
    static void m_merge_insertion_sort(T& container, int pair_level, int& comparisons);

    template <typename T>
    static void m_swap_buns(T it, int pair_level);

    void swap_buns(std::vector<int>::iterator it, int bun_size);

    template <typename T>
    static bool weigh_buns(T left_bun, T right_bun) {
        if (sizeof(T) == sizeof(std::vector<int>::iterator)) {
            comparisons_vec++;
        } else if (sizeof(T) == sizeof(std::deque<int>::iterator)) {
            comparisons_deq++;
        }
        return *left_bun < *right_bun;
    }

    template <typename T>
    static T next(T it, int steps) {
        std::advance(it, steps);
        return it;
    }
};

long jacobsthal_recipe(long n);
