/*
** EPITECH PROJECT, 2020
** QuickSort.hpp
** File description:
**
*/

#include "sortingAlgo/QuickSort.hpp"

void QuickSort::sort(std::vector<int> &toSort, float msToWaitAfterUpdate)
{
    quickSort(toSort, 0, toSort.size() - 1, msToWaitAfterUpdate);
}

void QuickSort::quickSort(std::vector<int> &toSort, int low, int high, float ms)
{
    if (low < high) {
        int pi = partition(toSort, low, high, ms);
        quickSort(toSort, low, pi - 1, ms);
        quickSort(toSort, pi + 1, high, ms);
    }
}

int QuickSort::partition(std::vector<int> &toSort, int low, int high, float ms)
{
    int pivot = toSort[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (toSort[j] < pivot) {
            i++;
            int t = toSort[i];
            toSort[i] = toSort[j];
            toSort[j] = t;
        }
        waitFor(ms);
    }
    int t = toSort[i + 1];
    toSort[i + 1] = toSort[high];
    toSort[high] = t;
    waitFor(ms);
    return (i + 1);
}