/*
** EPITECH PROJECT, 2020
** Visualizer.hpp
** File description:
**
*/

#ifndef SORTINGVISUALIZER_VISUALIZEUR_HPP
#define SORTINGVISUALIZER_VISUALIZEUR_HPP

#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
#include <iostream>
#include <chrono>
#include "ISortAlgo.hpp"
#include "utils.hpp"

template<typename T>
class Visualizer : public sf::Drawable {
    enum class State {
        Sort,
        Pause,
        Finish
    };
public:
    Visualizer(const sf::Vector2f &position = {0, 0},
               const sf::Vector2f &dimension = {800, 600},
               const sf::Vector2f &shapeOffset = {0, 0},
               const sf::Color &colorBar = {255, 255, 255, 255},
               bool reverse = false);
    void finish();
    void continu();
    void setSortingAlgo(ISortAlgo<T> *algo);
    void setDataFromRandom(int min, int max, int nb);
    void setDataFrom(const std::vector<T> &dataVec);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setUpdateTime(float ms);
    bool isReverse() const;
    void setReverse(bool isReverse);
    const sf::Vector2f &getPosition() const;
    void setPosition(const sf::Vector2f &position);
    const sf::Vector2f &getDimension() const;
    void setDimension(const sf::Vector2f &dimension);
    const sf::Vector2f &getShapeOffset() const;
    void setShapeOffset(const sf::Vector2f &shapeOffset);
    const sf::Color &getColorBar() const;
    void setColorBar(const sf::Color &colorBar);
    const State &getState() const;
    void setState(const State &state);
protected:
    std::vector<T> _data;
    ISortAlgo<T> *_sortingAlgo{nullptr};
    std::vector<sf::RectangleShape> _bars;
    float _msToWaitAfterUpdate{100};
    bool _isReverse;
    sf::Vector2f _position;
    sf::Vector2f _dimension;
    sf::Vector2f _shapeOffset;
    sf::Color _colorBar;
    State _state{State::Sort};
private:
    std::default_random_engine _randomEngine;
    T _maxElement;
    sf::Clock _clockUpdate;
    int _barSucceed{0};
};

#include "../src/Visualizer.cpp"

#endif //SORTINGVISUALIZEUR_VISUALIZER_HPP

