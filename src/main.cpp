/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
**
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Visualizer.hpp"
#include "sortingAlgo/BubbleSort.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualizeur");

    std::shared_ptr<BubbleSort> bubbleSort = std::make_shared<BubbleSort>();
    Visualizer visualizer;
    visualizer.setSortingAlgo(bubbleSort.get());
    visualizer.setDataFromRandom(0, 100,  250);

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