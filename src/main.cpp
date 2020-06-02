/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
**
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Visualizer.hpp"
#include "sortingAlgo/allSortingAlgo.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualizeur");

    auto sortAlgo = std::make_shared<CocktailSort>();
    Visualizer visualizer;
    visualizer.setUpdateTime(3);
    visualizer.setSortingAlgo(sortAlgo.get());
    visualizer.setDataFromRandom(0, 100,  300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        visualizer.update();
        window.draw(visualizer);
        window.display();
    }
    return EXIT_SUCCESS;
}