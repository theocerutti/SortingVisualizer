/*
** EPITECH PROJECT, 2020
** BubbleSort.hpp
** File description:
**
*/

#include "sortingAlgo/BubbleSort.hpp"

void BubbleSort::sort(std::vector<int> &toSort)
{
    if (_i > toSort.size())
        return;
    for (int j = 0; j < toSort.size() - 1; j++) {
        if (toSort[j] > toSort[j+1]) {
            int temp = toSort[j];
            toSort[j] = toSort[j+1];
            toSort[j+1] = temp;
        }
    }
    _i++;
}