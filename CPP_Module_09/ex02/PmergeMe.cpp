#include "PmergeMe.hpp"
#include <cmath>
#include <deque>

int PmergeMe::comparisons_vec = 0;
int PmergeMe::comparisons_deq = 0;

long _jacobsthal_number(long n) {
    return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

template <typename T>
void PmergeMe::_swap_pair(T it, int pair_level) {
    T start = next(it, -pair_level + 1);
    T end = next(start, pair_level);
    while (start != end) {
        std::iter_swap(start, next(start, pair_level));
        start++;
    }
}

template <typename T>
void PmergeMe::_merge_insertion_sort(T& container, int pair_level, int& comparisons) {
    typedef typename T::iterator Iterator;

    int pair_units_nbr = container.size() / pair_level;
    if (pair_units_nbr < 2)
        return;

    bool is_odd = pair_units_nbr % 2 == 1;

    Iterator start = container.begin();
    Iterator last = next(container.begin(), pair_level * (pair_units_nbr));
    Iterator end = next(last, -(is_odd * pair_level));

    int jump = 2 * pair_level;
    for (Iterator it = start; it != end; std::advance(it, jump)) {
        Iterator this_pair = next(it, pair_level - 1);
        Iterator next_pair = next(it, pair_level * 2 - 1);
        comparisons++; // Увеличиваем счетчик сравнений
        if (*this_pair > *next_pair) {
            _swap_pair(this_pair, pair_level);
        }
    }

    _merge_insertion_sort(container, pair_level * 2, comparisons);

    std::vector<Iterator> main;
    std::vector<Iterator> pend;

    main.insert(main.end(), next(container.begin(), pair_level - 1));
    main.insert(main.end(), next(container.begin(), pair_level * 2 - 1));

    for (int i = 4; i <= pair_units_nbr; i += 2) {
        pend.insert(pend.end(), next(container.begin(), pair_level * (i - 1) - 1));
        main.insert(main.end(), next(container.begin(), pair_level * i - 1));
    }

    int prev_jacobsthal = _jacobsthal_number(1);
    int inserted_numbers = 0;
    for (int k = 2;; k++) {
        int curr_jacobsthal = _jacobsthal_number(k);
        int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
        int offset = 0;
        if (jacobsthal_diff > static_cast<int>(pend.size()))
            break;
        int nbr_of_times = jacobsthal_diff;
        typename std::vector<Iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
        typename std::vector<Iterator>::iterator bound_it =
            next(main.begin(), curr_jacobsthal + inserted_numbers);
        while (nbr_of_times) {
            typename std::vector<Iterator>::iterator idx =
                std::upper_bound(main.begin(), bound_it, *pend_it, _comp<Iterator>);
            typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
            nbr_of_times--;
            pend_it = pend.erase(pend_it);
            std::advance(pend_it, -1);
            offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
            bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
        }
        prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
        offset = 0;
    }

    for (size_t i = 0; i < pend.size(); i++) {
        typename std::vector<Iterator>::iterator curr_pend = next(pend.begin(), i);
        typename std::vector<Iterator>::iterator curr_bound =
            next(main.begin(), main.size() - pend.size() + i);
        typename std::vector<Iterator>::iterator idx =
            std::upper_bound(main.begin(), curr_bound, *curr_pend, _comp<Iterator>);
        main.insert(idx, *curr_pend);
    }

    if (is_odd) {
        typename T::iterator odd_pair = next(end, pair_level - 1);
        typename std::vector<Iterator>::iterator idx =
            std::upper_bound(main.begin(), main.end(), odd_pair, _comp<Iterator>);
        main.insert(idx, odd_pair);
    }

    std::vector<int> copy;
    copy.reserve(container.size());
    for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++) {
        for (int i = 0; i < pair_level; i++) {
            Iterator pair_start = *it;
            std::advance(pair_start, -pair_level + i + 1);
            copy.insert(copy.end(), *pair_start);
        }
    }

    Iterator container_it = container.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end()) {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
    }
}

void PmergeMe::merge_insertion_sort(std::vector<int>& vec, double& time_vec) {
    clock_t start = clock();
    comparisons_vec = 0;
    _merge_insertion_sort(vec, 1, comparisons_vec);
    clock_t end = clock();
    time_vec = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::merge_insertion_sort(std::deque<int>& deq, double& time_deq) {
    clock_t start = clock();
    comparisons_deq = 0;
    _merge_insertion_sort(deq, 1, comparisons_deq);
    clock_t end = clock();
    time_deq = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
}