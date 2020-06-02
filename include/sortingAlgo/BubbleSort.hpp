/*
** EPITECH PROJECT, 2020
** BubbleSort.hpp
** File description:
**
*/

#ifndef SORTINGVISUALIZER_BUBBLESORT_HPP
#define SORTINGVISUALIZER_BUBBLESORT_HPP

#include "ISortAlgo.hpp"
#include <algorithm>
#include <random>

class BubbleSort : public ISortAlgo {
public:
    BubbleSort() = default;
    void sort(std::vector<int> &toSort) override;
private:
    int _i{0};
};

#endif //SORTINGVISUALIZER_BUBBLESORT_HPP
