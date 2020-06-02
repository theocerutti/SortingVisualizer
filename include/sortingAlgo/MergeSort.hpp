/*
** EPITECH PROJECT, 2020
** MergeSort.hpp
** File description:
**
*/

#ifndef SORTINGVISUALIZER_MERGESORT_HPP
#define SORTINGVISUALIZER_MERGESORT_HPP

#include "ISortAlgo.hpp"

class MergeSort : public ISortAlgo {
public:
    MergeSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;
};

#endif //SORTINGVISUALIZER_MERGESORT_HPP
