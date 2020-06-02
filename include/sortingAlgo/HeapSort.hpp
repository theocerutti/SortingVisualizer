/*
** EPITECH PROJECT, 2020
** HeapSort.hpp
** File description:
**
*/

#ifndef SORTINGVISUALIZER_HEAPSORT_HPP
#define SORTINGVISUALIZER_HEAPSORT_HPP

#include "ISortAlgo.hpp"

class HeapSort : public ISortAlgo {
public:
    HeapSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;

private:
    void heapify(std::vector<int> &toSort, int n, int i, float ms);
};

#endif //SORTINGVISUALIZER_HEAPSORT_HPP
