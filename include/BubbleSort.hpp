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

template<typename T>
class BubbleSort : public ISortAlgo<T> {
public:
    BubbleSort() = default;
    void sort(std::vector<T> &toSort) override;
};

#include "../src/BubbleSort.cpp"

#endif //SORTINGVISUALIZER_BUBBLESORT_HPP
