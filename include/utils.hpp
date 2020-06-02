/*
** EPITECH PROJECT, 2020
** utils.hpp
** File description:
**
*/

#ifndef SORTINGVISUALIZER_UTILS_HPP
#define SORTINGVISUALIZER_UTILS_HPP

#include <iostream>

namespace my {
    template<typename T = float>
    T clamp(const T& n, const T& lower, const T& upper) {
        return std::max(lower, std::min(n, upper));
    }

    template<typename T = float>
    T lerp(T a, T b, T f)
    {
        return (a + f * (b - a));
    }
}

#endif //SORTINGVISUALIZER_UTILS_HPP
