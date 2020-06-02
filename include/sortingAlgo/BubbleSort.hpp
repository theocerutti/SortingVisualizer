/*
** EPITECH PROJECT, 2020
** BubbleSort.hpp
** File description:
**
*/

#ifndef SORTINGVISUALIZER_BUBBLESORT_HPP
#define SORTINGVISUALIZER_BUBBLESORT_HPP

#include "ISortAlgo.hpp"

class BubbleSort : public ISortAlgo {
public:
    BubbleSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;
};

#endif //SORTINGVISUALIZER_BUBBLESORT_HPP
