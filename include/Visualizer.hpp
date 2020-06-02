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

class Visualizer : public sf::Drawable {
    enum class State {
        Sort,
        Pause,
        Finish
    };
public:
    /*
     * Constructor
     */
    explicit Visualizer(
       const sf::Vector2f &position = {0, 0},
       const sf::Vector2f &dimension = {800, 600},
       const sf::Vector2f &shapeOffset = {0, 0},
       const sf::Color &colorBar = {255, 255, 255, 255},
       bool reverse = false
    );

    /*
     * Draw function
     */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    /*
     * Update function
     */
    void update();

    /*
     * Set the sorting algorithm
     */
    void setSortingAlgo(ISortAlgo *algo);

    /*
     * Populate data randomly
     */
    void setDataFromRandom(int min, int max, int nb);

    /*
     * Populate data with a vector
     */
    void setDataFrom(const std::vector<int> &dataVec);

    /*
     * Getter & Setter of _msToWaitAfterCheckFinish
     */
    float getFinishTime() const;
    void setFinishTime(float ms);

    /*
     * Getter & Setter of _msToWaitAfterUpdate
     */
    float getUpdateTime() const;
    void setUpdateTime(float ms);

    /*
     * Getter & Setter of _isReverse
     */
    bool isReverse() const;
    void setReverse(bool isReverse);

    /*
     * Getter & Setter of _position
     */
    const sf::Vector2f &getPosition() const;
    void setPosition(const sf::Vector2f &position);

    /*
     * Getter & Setter of _dimension
     */
    const sf::Vector2f &getDimension() const;
    void setDimension(const sf::Vector2f &dimension);

    /*
     * Getter & Setter of _shapeOffset
     */
    const sf::Vector2f &getShapeOffset() const;
    void setShapeOffset(const sf::Vector2f &shapeOffset);

    /*
     * Getter & Setter of _colorBar
     */
    void setColorBar(const sf::Color &color);
    const sf::Color &getColorBar() const;

    /*
     * Getter & Setter of _state
     */
    const State &getState() const;;
    void setState(const State &state);
protected:
    std::vector<int> _data;
    ISortAlgo *_sortingAlgo{nullptr};
    std::vector<sf::RectangleShape> _bars;
    float _msToWaitAfterUpdate{100};
    float _msToWaitAfterCheckFinish{20};
    bool _isReverse;
    sf::Vector2f _position;
    sf::Vector2f _dimension;
    sf::Vector2f _shapeOffset;
    sf::Color _colorBar;
    State _state{State::Sort};
private:
    std::default_random_engine _randomEngine;
    int _maxElement;
    sf::Clock _clockUpdate;
    sf::Clock _clockFinish;
    int _barSucceed{0};
};

#endif //SORTINGVISUALIZEUR_VISUALIZER_HPP

