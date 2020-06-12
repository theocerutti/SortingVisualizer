/*
** EPITECH PROJECT, 2020
** IterativeQuickSort.hpp
** File description:
**
*/

#include "sortingAlgo/IterativeQuickSort.hpp"
#include <iostream>

void IterativeQuickSort::sort(std::vector<int> &toSort, float msToWaitAfterUpdate)
{
    quickSort(toSort, 0, toSort.size() - 1, msToWaitAfterUpdate);
}

void IterativeQuickSort::quickSort(std::vector<int> &toSort, int l, int h, float ms)
{
    if (l < h) {
        int p = partition(toSort, l, h, ms);
        quickSort(toSort, l, p - 1, ms);
        quickSort(toSort, p + 1, h, ms);
    }
}

int IterativeQuickSort::partition(std::vector<int> &toSort, int l, int h, float ms)
{
    std::cout << h << " " << toSort.size() << std::endl;
    int x = toSort[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (toSort[j] <= x) {
            i++;
            int temp = toSort[i];
            toSort[i] = toSort[j];
            toSort[j] = temp;
            waitFor(ms);
        }
    }
    int temp = toSort[i + 1];
    toSort[i + 1] = toSort[h];
    toSort[h] = temp;
    waitFor(ms);
    return (i + 1);
}