/*
** EPITECH PROJECT, 2020
** Visualizer.hpp
** File description:
**
*/

#include "Visualizer.hpp"

Visualizer::Visualizer(const sf::Vector2f &position,
                       const sf::Vector2f &dimension,
                       const sf::Vector2f &shapeOffset,
                       const sf::Color &colorBar,
                       bool reverse) :
        _randomEngine(std::chrono::system_clock::now().time_since_epoch().count()),
        _isReverse(reverse),
        _position(position),
        _dimension(dimension),
        _shapeOffset(shapeOffset),
        _colorBar(colorBar)
{
}

void Visualizer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const sf::RectangleShape &bar : _bars)
    target.draw(bar);
}

void Visualizer::update()
{
    if (_sortingAlgo && _data.size() > 1 && _state != State::Pause) {
        if (_state == State::Sort && _clockUpdate.getElapsedTime().asMilliseconds() > _msToWaitAfterUpdate) {
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
            }
            if (std::is_sorted(_data.begin(), _data.end()))
                _state = State::Finish;
            _clockUpdate.restart();
        } else if (_state == State::Finish && _clockFinish.getElapsedTime().asMilliseconds() > _msToWaitAfterCheckFinish) {
            if (_barSucceed < _data.size()) {
                _bars[_barSucceed].setFillColor(sf::Color(0, 255, 0, 255));
                _barSucceed += 1;
                _clockFinish.restart();
            } else {
                _state = State::Pause;
            }
        }
    }
}

void Visualizer::setSortingAlgo(ISortAlgo *algo)
{
    _sortingAlgo = algo;
}

void Visualizer::setDataFromRandom(int min, int max, int nb)
{
    std::uniform_int_distribution<int> distrib(min, max);

    _data.clear();
    _bars.clear();
    for (int i = 0; i < nb; i++) {
        _data.push_back(distrib(_randomEngine));
        _bars.emplace_back();
    }
    auto it = std::max_element(_data.begin(), _data.end());
    _maxElement = *it;
}

void Visualizer::setDataFrom(const std::vector<int> &dataVec)
{
    _data = dataVec;
    _bars.clear();
    for (auto &data : _data)
        _bars.emplace_back();
    auto it = std::max_element(_data.begin(), _data.end());
    _maxElement = *it;
}

float Visualizer::getUpdateTime() const
{
    return (_msToWaitAfterUpdate);
}

void Visualizer::setUpdateTime(float ms)
{
    _msToWaitAfterUpdate = ms;
}

bool Visualizer::isReverse() const
{
    return (_isReverse);
}

void Visualizer::setReverse(bool isReverse)
{
    _isReverse = isReverse;
}

const sf::Vector2f &Visualizer::getPosition() const
{
    return (_position);
}

void Visualizer::setPosition(const sf::Vector2f &position)
{
    _position = position;
}

const sf::Vector2f &Visualizer::getDimension() const
{
    return (_dimension);
}

void Visualizer::setDimension(const sf::Vector2f &dimension)
{
    _dimension = dimension;
}

const sf::Vector2f &Visualizer::getShapeOffset() const
{
    return (_shapeOffset);
}

void Visualizer::setShapeOffset(const sf::Vector2f &shapeOffset)
{
    _shapeOffset = shapeOffset;
}

const sf::Color &Visualizer::getColorBar() const
{
    return (_colorBar);
}

void Visualizer::setColorBar(const sf::Color &colorBar)
{
    _colorBar = colorBar;
}

const typename Visualizer::State &Visualizer::getState() const
{
    return (_state);
}

void Visualizer::setState(const Visualizer::State &state)
{
    _state = state;
}

void Visualizer::setFinishTime(float ms)
{
    _msToWaitAfterCheckFinish = ms;
}

float Visualizer::getFinishTime() const
{
    return (_msToWaitAfterCheckFinish);
}
