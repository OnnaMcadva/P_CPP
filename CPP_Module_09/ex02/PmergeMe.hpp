#pragma once

#include <algorithm>
#include <deque>
#include <vector>
#include <ctime>
#include <iostream>
#include <cmath>

class PmergeMe {
public:
    static int comparisons_vec;
    static int comparisons_deq;
    static void merge_insertion_sort(std::vector<int>& vec, double& time_vec);
    static void merge_insertion_sort(std::deque<int>& deq, double& time_deq);
private:
    static void Ford_Johnson(std::vector<int>& vec, int bun_size, int& compar);
    static void Ford_Johnson(std::deque<int>& deq, int bun_size, int& compar);
    static void swap_buns(std::vector<int>::iterator it, int bun_size);
    static void swap_buns(std::deque<int>::iterator it, int bun_size);
    static bool weigh_vec_buns(std::vector<int>::iterator left_bun, std::vector<int>::iterator right_bun) {
        comparisons_vec++;
        return *left_bun < *right_bun;
    }
    static bool weigh_deq_buns(std::deque<int>::iterator left_bun, std::deque<int>::iterator right_bun) {
        comparisons_deq++;
        return *left_bun < *right_bun;
    }
    static bool ccompare_vec_iters(std::vector<int>::iterator left, std::vector<int>::iterator right) {
        comparisons_vec++;
        return *left < *right;
    }
    static bool compare_deq_iters(std::deque<int>::iterator left, std::deque<int>::iterator right) {
        comparisons_deq++;
        return *left < *right;
    }
    static std::vector<int>::iterator moveIt(std::vector<int>::iterator it, int steps) {
        std::advance(it, steps);
        return it;
    }
    static std::vector<std::vector<int>::iterator>::iterator moveIt(std::vector<std::vector<int>::iterator>::iterator it, int steps) {
        std::advance(it, steps);
        return it;
    }
    static std::deque<int>::iterator moveIt(std::deque<int>::iterator it, int steps) {
        std::advance(it, steps);
        return it;
    }
    static std::deque<std::deque<int>::iterator>::iterator moveIt(std::deque<std::deque<int>::iterator>::iterator it, int steps) {
        std::advance(it, steps);
        return it;
    }
    static long jacobsthal_recipe(long n);
    static int get_jacobsthal_count(int k, int tray_size);
    static void insert_from_tray(std::vector<std::vector<int>::iterator>& oven, 
                                std::vector<std::vector<int>::iterator>& tray, 
                                std::vector<std::vector<int>::iterator>::iterator& tray_it, 
                                int baked_count, int& shift);
    static void insert_from_tray(std::deque<std::deque<int>::iterator>& oven, 
                                std::deque<std::deque<int>::iterator>& tray, 
                                std::deque<std::deque<int>::iterator>::iterator& tray_it, 
                                int baked_count, int& shift);
};