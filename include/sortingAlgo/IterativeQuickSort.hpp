#ifndef SORTINGVISUALIZER_ITERATIVEQUICKSORT_HPP
#define SORTINGVISUALIZER_ITERATIVEQUICKSORT_HPP

#include "ISortAlgo.hpp"

class IterativeQuickSort : public ISortAlgo {
public:
    IterativeQuickSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;

private:
    void quickSort(std::vector<int> &toSort, int l, int h, float ms);
    int partition(std::vector<int> &toSort, int l, int h, float ms);
};

#endif //SORTINGVISUALIZER_ITERATIVEQUICKSORT_HPP
