#ifndef SORTINGVISUALIZER_ISORTALGO_HPP
#define SORTINGVISUALIZER_ISORTALGO_HPP

#include <vector>
#include <thread>
#include <chrono>

class ISortAlgo {
public:
    /*
     * Called each frame. Need to do one action
     */
    virtual void sort(std::vector<int> &toSort, float msToWaitAfterUpdate) = 0;

    /*
     * Wait call for stop the thread and let sfml draw changes
     */
    virtual void waitFor(float ms) const
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(ms)));
    }
};

#endif //SORTINGVISUALIZER_ISORTALGO_HPP
