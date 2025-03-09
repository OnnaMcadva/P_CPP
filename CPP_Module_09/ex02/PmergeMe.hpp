#pragma once

#include <algorithm>
#include <deque>
#include <vector>
#include <ctime>
#include <iostream>
#include <cmath>

class PmergeMe {
public:
    static int comparisons_deq;
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    static void merge_insertion_sort(std::vector<int>& vec, double& time_vec);
    static void merge_insertion_sort(std::deque<int>& deq, double& time_deq);
private:
    static void Ford_Johnson(std::vector<int>& vec, int bun_size);
    static void Ford_Johnson(std::deque<int>& deq, int bun_size);
    static void swap_buns(std::deque<int>::iterator it, int bun_size);
    static bool compare_deq_iters(std::deque<int>::iterator left, std::deque<int>::iterator right);
    static std::deque<int>::iterator moveIt(std::deque<int>::iterator it, int steps);
    static std::deque<std::deque<int>::iterator>::iterator moveIt(std::deque<std::deque<int>::iterator>::iterator it, int steps);
    static long jacobsthal_recipe(long n);
    static int get_jacobsthal_count(int k, int tray_size);
    static void insert_from_tray(std::vector<int>& oven,
                                std::vector<int>& tray,
                                std::vector<int>::iterator& tray_it,
                                int baked_count,
                                int& shift);
    static void insert_from_tray(std::deque<std::deque<int>::iterator>& oven, 
                                std::deque<std::deque<int>::iterator>& tray, 
                                std::deque<std::deque<int>::iterator>::iterator& tray_it, 
                                int baked_count, int& shift);
};