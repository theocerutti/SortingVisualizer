/*
** EPITECH PROJECT, 2020
** QuickSort.hpp
** File description:
**
*/

#ifndef SORTINGVISUALIZER_QUICKSORT_HPP
#define SORTINGVISUALIZER_QUICKSORT_HPP

#include "ISortAlgo.hpp"

class QuickSort : public ISortAlgo {
public:
    QuickSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;

private:
    void quickSort(std::vector<int> &toSort, int low, int high, float ms);
    int partition(std::vector<int> &toSort, int low, int high, float ms);
};

#endif //SORTINGVISUALIZER_QUICKSORT_HPP
