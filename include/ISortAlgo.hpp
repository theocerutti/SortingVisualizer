/*
** EPITECH PROJECT, 2020
** $HEADER_FILENAME
** File description:
**
*/

#ifndef SORTINGVISUALIZER_ISORTALGO_HPP
#define SORTINGVISUALIZER_ISORTALGO_HPP

#include <vector>

template<typename T>
class ISortAlgo {
public:
    /*
     * Called each frame. Need to do one action
     */
    virtual void sort(std::vector<T> &toSort) = 0;
};

#endif //SORTINGVISUALIZER_ISORTALGO_HPP
