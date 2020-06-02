/*
** EPITECH PROJECT, 2020
** $HEADER_FILENAME
** File description:
**
*/

#ifndef SORTINGVISUALIZER_ISORTALGO_HPP
#define SORTINGVISUALIZER_ISORTALGO_HPP

#include <vector>

class ISortAlgo {
public:
    /*
     * Called each frame. Need to do one action
     */
    virtual void sort(std::vector<int> &toSort) = 0;
};

#endif //SORTINGVISUALIZER_ISORTALGO_HPP
