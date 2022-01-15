#ifndef SORTINGVISUALIZER_RADIXSORT_HPP
#define SORTINGVISUALIZER_RADIXSORT_HPP

#include "ISortAlgo.hpp"
#include <algorithm>

class RadixSort : public ISortAlgo {
public:
    RadixSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;

private:
    void countSort(std::vector<int> &toSort, int n, int exp, float ms);
    int getMax(std::vector<int> &toSort, int n);
};

#endif //SORTINGVISUALIZER_RADIXSORT_HPP
