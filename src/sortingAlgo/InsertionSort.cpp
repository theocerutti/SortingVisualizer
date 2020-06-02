/*
** EPITECH PROJECT, 2020
** InsertionSort.hpp
** File description:
**
*/

#include "sortingAlgo/InsertionSort.hpp"

void InsertionSort::sort(std::vector<int> &toSort, float msToWaitAfterUpdate)
{
    int i, key, j = 0;
    int n = toSort.size();

    for (i = 1; i < n; i++) {
        key = toSort[i];
        j = i - 1;

        while (j >= 0 && toSort[j] > key) {
            toSort[j + 1] = toSort[j];
            waitFor(msToWaitAfterUpdate);
            j = j - 1;
        }
        toSort[j + 1] = key;
    }
}
