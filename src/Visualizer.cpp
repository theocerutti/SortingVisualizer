/*
** EPITECH PROJECT, 2020
** Visualizer.hpp
** File description:
**
*/

#include "Visualizer.hpp"

#ifndef SORTINGVISUALIZER_VISUALIZEUR_CPP
#define SORTINGVISUALIZER_VISUALIZEUR_CPP

template<typename T>
Visualizer<T>::Visualizer(const sf::Vector2f &position,
                          const sf::Vector2f &dimension,
                          const sf::Vector2f &shapeOffset,
                          const sf::Color &colorBar,
                          bool isReverse)
    : _randomEngine(std::chrono::system_clock::now().time_since_epoch().count()),
    _isReverse(isReverse),
    _position(position),
    _dimension(dimension),
    _shapeOffset(shapeOffset),
    _colorBar(colorBar)
{

}

template<typename T>
void Visualizer<T>::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &bar : _bars)
        target.draw(bar);
}

template<typename T>
void Visualizer<T>::update()
{
    if (_sortingAlgo && _clockUpdate.getElapsedTime().asMilliseconds() > _msToWaitAfterUpdate && _state != State::Pause) {
        if (_state == State::Sort) {
            _sortingAlgo->sort(_data);
            for (int i = 0; i < _data.size(); i++) {
                _bars[i].setFillColor(_colorBar);
                float sizeX = static_cast<float>(_dimension.x - (_shapeOffset.x * 2.f + _data.size()));
                if (sizeX < _data.size())
                    throw std::runtime_error("Visualizer is too small. Width must be greater than or equal (>=) to the half of the size of the contained data. (size.x >= data.size() / 2).");
                _bars[i].setSize(sf::Vector2f(
                    sizeX / _data.size(),
                    my::lerp<float>(0.f, _dimension.y - _shapeOffset.y * 2.f, ((float)_data[i] / (float)_maxElement)))
                );
                _bars[i].setPosition(
                    _position.x + _shapeOffset.x + (i * _bars[i].getSize().x) + i,
                    _isReverse ? (_position.y + _shapeOffset.y) : (_position.y - _shapeOffset.y - _bars[i].getSize().y + _dimension.y)
                );
                if (std::is_sorted(_data.begin(), _data.end()))
                    _state = State::Finish;
            }
            _clockUpdate.restart();
        } else if (_state == State::Finish) {
            if (_barSucceed < _data.size()) {
                _bars[_barSucceed].setFillColor(sf::Color(0, 255, 0, 255));
                _barSucceed += 1;
            } else {
                _state = State::Pause;
            }
        }
    }
}

template<typename T>
void Visualizer<T>::setSortingAlgo(ISortAlgo<T> *algo)
{
    _sortingAlgo = algo;
}

template<typename T>
void Visualizer<T>::setDataFromRandom(int min, int max, int nb)
{
    std::uniform_int_distribution<T> distrib(min, max);

    _data.clear();
    _bars.clear();
    for (int i = 0; i < nb; i++) {
        _data.push_back(distrib(_randomEngine));
        _bars.emplace_back();
    }
    auto it = std::max_element(_data.begin(), _data.end());
    _maxElement = *it;
}

template<typename T>
void Visualizer<T>::setDataFrom(const std::vector<T> &dataVec)
{
    _data = dataVec;
    _bars.clear();
    for (auto &data : _data)
        _bars.emplace_back();
    auto it = std::max_element(_data.begin(), _data.end());
    _maxElement = *it;
}

template<typename T>
void Visualizer<T>::setUpdateTime(float ms)
{
    _msToWaitAfterUpdate = ms;
}

template<typename T>
bool Visualizer<T>::isReverse() const
{
    return (_isReverse);
}

template<typename T>
void Visualizer<T>::setReverse(bool isReverse)
{
    _isReverse = isReverse;
}

template<typename T>
const sf::Vector2f &Visualizer<T>::getPosition() const
{
    return (_position);
}

template<typename T>
void Visualizer<T>::setPosition(const sf::Vector2f &position)
{
    _position = position;
}

template<typename T>
const sf::Vector2f &Visualizer<T>::getDimension() const
{
    return (_dimension);
}

template<typename T>
void Visualizer<T>::setDimension(const sf::Vector2f &dimension)
{
    _dimension = dimension;
}

template<typename T>
const sf::Vector2f &Visualizer<T>::getShapeOffset() const
{
    return (_shapeOffset);
}

template<typename T>
void Visualizer<T>::setShapeOffset(const sf::Vector2f &shapeOffset)
{
    _shapeOffset = shapeOffset;
}

template<typename T>
const sf::Color &Visualizer<T>::getColorBar() const
{
    return (_colorBar);
}

template<typename T>
void Visualizer<T>::setColorBar(const sf::Color &colorBar)
{
    _colorBar = colorBar;
}

template<typename T>
const typename Visualizer<T>::State &Visualizer<T>::getState() const
{
    return (_state);
}

template<typename T>
void Visualizer<T>::setState(const Visualizer::State &state)
{
    _state = state;
}

#endif
