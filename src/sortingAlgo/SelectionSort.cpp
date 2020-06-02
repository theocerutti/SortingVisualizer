/*
** EPITECH PROJECT, 2020
** SelectionSort.hpp
** File description:
**
*/

#include "sortingAlgo/SelectionSort.hpp"

void SelectionSort::sort(std::vector<int> &toSort, float msToWaitAfterUpdate)
{
    int i, j, min_idx = 0;
    int n = toSort.size();

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (toSort[j] < toSort[min_idx])
                min_idx = j;
        int temp = toSort[min_idx];
        toSort[min_idx] = toSort[i];
        toSort[i] = temp;
        waitFor(msToWaitAfterUpdate);
    }
}