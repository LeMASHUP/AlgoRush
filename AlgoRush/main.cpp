#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

#include "Level1.h"
#include "Level2.h"

int main()
{
    int level = 1;

    srand(time(0));

    Vector2f gravity(0, 1.0);
    sfp::World world(gravity);

    sf::Clock clock;
    sf::Time lastTime = clock.getElapsedTime();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Not Tetris");

    sf::Event event;

    //Creation of levels;
    Level1 level1(&world);
    Level2 level2(&world);

    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }

        sf::Time currentTime = clock.getElapsedTime();
        unsigned long elapsedMs = (currentTime - lastTime).asMilliseconds();

        if (elapsedMs > 0) {
            lastTime = currentTime;
            world.UpdatePhysics(elapsedMs);
            window.clear(sf::Color::Black);
            if (level == 1) level1.DrawLevels(&window);
            else if (level == 2) level2.DrawLevels(&window);
            window.display();
        }
    }

    return 0;
}