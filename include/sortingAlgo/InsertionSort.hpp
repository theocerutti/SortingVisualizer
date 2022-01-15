#ifndef SORTINGVISUALIZER_INSERTIONSORT_HPP
#define SORTINGVISUALIZER_INSERTIONSORT_HPP

#include "ISortAlgo.hpp"

class InsertionSort : public ISortAlgo {
public:
    InsertionSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;
};

#endif //SORTINGVISUALIZER_INSERTIONSORT_HPP
