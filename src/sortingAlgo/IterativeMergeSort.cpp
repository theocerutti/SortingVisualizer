/*
** EPITECH PROJECT, 2020
** IterativeMergeSort.hpp
** File description:
**
*/

#include "sortingAlgo/IterativeMergeSort.hpp"

void IterativeMergeSort::sort(std::vector<int> &toSort, float msToWaitAfterUpdate)
{
    mergeSort(toSort, 0, toSort.size() - 1, msToWaitAfterUpdate);
}

void IterativeMergeSort::mergeSort(std::vector<int> &toSort, int l, int r, float ms)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(toSort, l, m, ms);
        mergeSort(toSort, m + 1, r, ms);
        merge(toSort, l, m, r, ms);
    }
}

void IterativeMergeSort::merge(std::vector<int> &toSort, int l, int m, int r, float ms)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
        L[i] = toSort[l + i];
    for (j = 0; j < n2; j++)
        R[j] = toSort[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            toSort[k] = L[i];
            i++;
        } else {
            toSort[k] = R[j];
            j++;
        }
        k++;
        waitFor(ms);
    }
    while (i < n1) {
        toSort[k] = L[i];
        i++;
        k++;
        waitFor(ms);
    }
    while (j < n2) {
        toSort[k] = R[j];
        j++;
        k++;
        waitFor(ms);
    }
}