#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Visualizer.hpp"
#include "sortingAlgo/allSortingAlgo.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualizer");

    auto sortAlgo = std::make_shared<SelectionSort>();
    Visualizer visualizer1;
    visualizer1.setUpdateTime(3);
    visualizer1.setFinishTime(0.3);
    visualizer1.setSortingAlgo(sortAlgo.get());
    visualizer1.setDataFromRandom(0, 100,  200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        visualizer1.update();
        window.draw(visualizer1);
        window.display();
    }
    return EXIT_SUCCESS;
}
