/*
** EPITECH PROJECT, 2020
** RadixSort.hpp
** File description:
**
*/

#include "sortingAlgo/RadixSort.hpp"

void RadixSort::sort(std::vector<int> &toSort, float msToWaitAfterUpdate)
{
    int max = getMax(toSort, toSort.size());
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(toSort, toSort.size() + 1, exp, msToWaitAfterUpdate);
}

void RadixSort::countSort(std::vector<int> &toSort, int n, int exp, float ms)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (toSort[i] / exp) % 10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[ (toSort[i] / exp) % 10 ] - 1] = toSort[i];
        count[ (toSort[i] / exp) % 10 ]--;
    }

    for (i = 0; i < n; i++) {
        toSort[i] = output[i];
        waitFor(ms);
    }
}

int RadixSort::getMax(std::vector<int> &toSort, int n)
{
    int mx = toSort[0];
    for (int i = 1; i < n; i++)
        if (toSort[i] > mx)
            mx = toSort[i];
    return mx;
}
