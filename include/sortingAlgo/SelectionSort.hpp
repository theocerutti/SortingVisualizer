/*
** EPITECH PROJECT, 2020
** SelectionSort.hpp
** File description:
**
*/

#ifndef SORTINGVISUALIZER_SELECTIONSORT_HPP
#define SORTINGVISUALIZER_SELECTIONSORT_HPP

#include "ISortAlgo.hpp"

class SelectionSort : public ISortAlgo {
public:
    SelectionSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;
};

#endif //SORTINGVISUALIZER_SELECTIONSORT_HPP
