#ifndef SORTINGVISUALIZER_ITERATIVEMERGESORT_HPP
#define SORTINGVISUALIZER_ITERATIVEMERGESORT_HPP

#include "ISortAlgo.hpp"

class IterativeMergeSort : public ISortAlgo {
public:
    IterativeMergeSort() = default;
    void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) override;

private:
    void mergeSort(std::vector<int> &toSort, int l, int r, float ms);
    void merge(std::vector<int> &toSort, int l, int m, int r, float ms);
};

#endif //SORTINGVISUALIZER_ITERATIVEMERGESORT_HPP
