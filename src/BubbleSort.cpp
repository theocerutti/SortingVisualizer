/*
** EPITECH PROJECT, 2020
** BubbleSort.hpp
** File description:
**
*/

#include "BubbleSort.hpp"

#ifndef SORTINGVISUALIZER_BUBBLESORT_CPP
#define SORTINGVISUALIZER_BUBBLESORT_CPP

template<typename T>
void BubbleSort<T>::sort(std::vector<T> &toSort)
{
    for (int i = 0; i < toSort.size(); i++) {
        for (int j = 0; j < toSort.size() - 1; j++) {
            if (toSort[j] > toSort[j+1]) {
                int temp = toSort[j];
                toSort[j] = toSort[j+1];
                toSort[j+1] = temp;
            }
        }
    }
}

#endif