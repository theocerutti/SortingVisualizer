/*
** EPITECH PROJECT, 2020
** CocktailSort.hpp
** File description:
**
*/

#ifndef SORTINGVISUALIZER_COCKTAILSORT_HPP
#define SORTINGVISUALIZER_COCKTAILSORT_HPP

#include "ISortAlgo.hpp"

class CocktailSort : public ISortAlgo {
public:
    CocktailSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;
};

#endif //SORTINGVISUALIZER_COCKTAILSORT_HPP
