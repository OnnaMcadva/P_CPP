#pragma once

#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <cmath>

class PmergeMe {
public:

    static int comparisons_vec;
    static int comparisons_deq;

    static int jacobsthal(int n);
    static int jacobsthal_modified(int n);

    static void merge_insertion_sort(std::vector<int>& vec, double& time);
    static void merge_insertion_sort(std::deque<int>& deq, double& time);

private:
    static void ford_johnson_algorithm(std::vector<int>& to_sort);
    static void ford_johnson_algorithm(std::deque<int>& to_sort);
};
