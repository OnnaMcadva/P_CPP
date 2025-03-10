#include "PmergeMe.hpp"
#include <cmath>
#include <deque>
#include <sys/time.h>
#include <iostream>

int PmergeMe::comparisons_vec = 0;
int PmergeMe::comparisons_deq = 0;

/* 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
    10 923, 21 845, 43 691, 87 381, 174 763, 349 525, … */

long jacobsthal_recipe(long n) {
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

template <typename T>
void PmergeMe::m_swap_buns(T it, int bun_size) {
    T start = next(it, -bun_size + 1);
    T end = next(start, bun_size);
    while (start != end) {
        std::iter_swap(start, next(start, bun_size));
        start++;
    }
}

template <typename T>
void PmergeMe::m_merge_insertion_sort(T& container, int bun_size, int& comparisons) {
    typedef typename T::iterator Iterator;

    int pair_units_nbr = container.size() / bun_size;
    if (pair_units_nbr < 2)
        return;

    bool is_odd = pair_units_nbr % 2 == 1;

    std::cout << "=== Начало сортировки ===" << std::endl;
    std::cout << "pair_level: " << bun_size << ", pair_units_nbr: " << pair_units_nbr << std::endl;
    std::cout << "is_odd: " << is_odd << std::endl;

    Iterator start = container.begin();
    Iterator finish = next(container.begin(), bun_size * (pair_units_nbr));
    Iterator dough = next(finish, -(is_odd * bun_size));

    std::cout << "start: " << *start << ", finish: " << *finish << ", tail: " << *dough << std::endl;

    int jump = 2 * bun_size;
    for (Iterator it = start; it != dough; std::advance(it, jump)) {
        Iterator this_pair = next(it, bun_size - 1);
        Iterator next_pair = next(it, bun_size * 2 - 1);
        comparisons++;
        //std::cout << "Сравниваем: " << *this_pair << " и " << *next_pair << std::endl;
        if (*this_pair > *next_pair) {
            //std::cout << "Меняем местами: " << *this_pair << " и " << *next_pair << std::endl;
            swap_buns(this_pair, bun_size);
        }
    }

    std::cout << "После сортировки пар: ";
    for (Iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    m_merge_insertion_sort(container, bun_size * 2, comparisons);

    std::vector<Iterator> oven;
    std::vector<Iterator> tray;

    oven.insert(oven.end(), next(container.begin(), bun_size - 1));
    oven.insert(oven.end(), next(container.begin(), bun_size * 2 - 1));

    for (int i = 4; i <= pair_units_nbr; i += 2) {
        tray.insert(tray.end(), next(container.begin(), bun_size * (i - 1) - 1));
        oven.insert(oven.end(), next(container.begin(), bun_size * i - 1));
    }

    std::cout << "main после инициализации: ";
    for (typename std::vector<Iterator>::iterator it = oven.begin(); it != oven.end(); ++it) {
        std::cout << **it << " ";
    }
    std::cout << std::endl;

    std::cout << "pend после инициализации: ";
    for (typename std::vector<Iterator>::iterator it = tray.begin(); it != tray.end(); ++it) {
        std::cout << **it << " ";
    }
    std::cout << std::endl;

    if (is_odd) {
        typename T::iterator odd_bun = next(dough, bun_size - 1);
        tray.insert(tray.end(), odd_bun);
        std::cout << "Нечётный элемент добавлен в pend: " << *odd_bun << std::endl;
    }

    int prev_jacobsthal = jacobsthal_recipe(1);
    int inserted_numbers = 0;
    for (int k = 2;; k++) {
        int curr_jacobsthal = jacobsthal_recipe(k);
        int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
        int offset = 0;
        if (jacobsthal_diff > static_cast<int>(tray.size()))
            break;
        int nbr_of_times = jacobsthal_diff;
        typename std::vector<Iterator>::iterator pend_it = next(tray.begin(), jacobsthal_diff - 1);
        typename std::vector<Iterator>::iterator bound_it =
            next(oven.begin(), curr_jacobsthal + inserted_numbers);
        std::cout << "Вставляем элементы из pend в main. Текущий Jacobsthal: " << curr_jacobsthal << std::endl;
        while (nbr_of_times) {
            typename std::vector<Iterator>::iterator idx =
                std::upper_bound(oven.begin(), bound_it, *pend_it, weigh_buns<Iterator>);
            typename std::vector<Iterator>::iterator inserted = oven.insert(idx, *pend_it);
            nbr_of_times--;
            pend_it = tray.erase(pend_it);
            std::advance(pend_it, -1);
            offset += (inserted - oven.begin()) == curr_jacobsthal + inserted_numbers;
            bound_it = next(oven.begin(), curr_jacobsthal + inserted_numbers - offset);
            std::cout << "Вставлен элемент: " << **inserted << std::endl;
        }
        prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
        offset = 0;
    }

    std::cout << "main после вставки элементов из pend: ";
    for (typename std::vector<Iterator>::iterator it = oven.begin(); it != oven.end(); ++it) {
        std::cout << **it << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < tray.size(); i++) {
        typename std::vector<Iterator>::iterator curr_pend = next(tray.begin(), i);
        typename std::vector<Iterator>::iterator curr_bound =
            next(oven.begin(), oven.size() - tray.size() + i);
        typename std::vector<Iterator>::iterator idx =
            std::upper_bound(oven.begin(), curr_bound, *curr_pend, weigh_buns<Iterator>);
        oven.insert(idx, *curr_pend);
        std::cout << "Вставлен оставшийся элемент: " << **curr_pend << std::endl;
    }

    std::vector<int> copy;
    copy.reserve(container.size());
    for (typename std::vector<Iterator>::iterator it = oven.begin(); it != oven.end(); it++) {
        for (int i = 0; i < bun_size; i++) {
            Iterator pair_start = *it;
            std::advance(pair_start, -bun_size + i + 1);
            copy.insert(copy.end(), *pair_start);
        }
    }

    std::cout << "copy после сборки: ";
    for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    Iterator container_it = container.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end()) {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
    }

    std::cout << "Итоговый контейнер: ";
    for (Iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "=== Конец сортировки ===" << std::endl;
}

double get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

void PmergeMe::merge_insertion_sort(std::vector<int>& vec, double& time_vec) {
    double start = get_current_time();
    comparisons_vec = 0;
    m_merge_insertion_sort(vec, 1, comparisons_vec);
    double end = get_current_time();
    time_vec = (end - start) * 1000000.0;
}

void PmergeMe::merge_insertion_sort(std::deque<int>& deq, double& time_deq) {
    double start = get_current_time();
    comparisons_deq = 0;
    m_merge_insertion_sort(deq, 1, comparisons_deq);
    double end = get_current_time();
    time_deq = (end - start) * 1000000.0;
}

