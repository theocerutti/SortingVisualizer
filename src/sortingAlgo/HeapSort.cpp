/*
** EPITECH PROJECT, 2020
** HeapSort.hpp
** File description:
**
*/

#include "sortingAlgo/HeapSort.hpp"

void HeapSort::sort(std::vector<int> &toSort, float msToWaitAfterUpdate)
{
    int n = toSort.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(toSort, n, i, msToWaitAfterUpdate);

    for (int i=n-1; i>0; i--) {
        int temp = toSort[0];
        toSort[0] = toSort[i];
        toSort[i] = temp;
        waitFor(msToWaitAfterUpdate);
        heapify(toSort, i, 0, msToWaitAfterUpdate);
    }
}

void HeapSort::heapify(std::vector<int> &toSort, int n, int i, float ms)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && toSort[l] > toSort[largest])
        largest = l;

    if (r < n && toSort[r] > toSort[largest])
        largest = r;

    if (largest != i) {
        int temp = toSort[i];
        toSort[i] = toSort[largest];
        toSort[largest] = temp;
        waitFor(ms);
        heapify(toSort, n, largest, ms);
    }
}