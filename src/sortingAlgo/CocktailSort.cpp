/*
** EPITECH PROJECT, 2020
** CocktailSort.hpp
** File description:
**
*/

#include "sortingAlgo/CocktailSort.hpp"

void CocktailSort::sort(std::vector<int> &toSort, float msToWaitAfterUpdate)
{
    bool swapped = true;
    int start = 0;
    int end = toSort.size();

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (i + 1 < toSort.size() && toSort[i] > toSort[i + 1]) {
                int temp = toSort[i];
                toSort[i] = toSort[i + 1];
                toSort[i + 1] = temp;
                swapped = true;
                waitFor(msToWaitAfterUpdate);
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (toSort[i] > toSort[i + 1]) {
                int temp = toSort[i];
                toSort[i] = toSort[i + 1];
                toSort[i + 1] = temp;
                swapped = true;
                waitFor(msToWaitAfterUpdate);
            }
        }
        ++start;
    }
}