#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

#include "Level1.h"
#include "Level2.h"

int main()
{
    int state = 1;
    bool levelCreated = false;
    //Levels* ptr_levels = nullptr;

    srand(time(0));

    Vector2f gravity(0, 1.0);
    sfp::World world(gravity);

    sf::Clock clock;
    sf::Time lastTime = clock.getElapsedTime();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Not Tetris");
    window.setFramerateLimit(60);

    sf::Event event;

    Level1 level1(&world);
    Level2 level2(&world);
    levelCreated = true;

    while (window.isOpen()) {

        ////Creation of levels;
        //switch (state)
        //{
        //    case 1:
        //    {
        //        Level1 level1(&world);
        //        ptr_levels = &level1;
        //        levelCreated = true;
        //        break;
        //    }
        //    case 2:
        //    {
        //        Level2 level2(&world);
        //        ptr_levels = &level2;
        //        levelCreated = true;
        //        break;
        //    }
        //    default:
        //        break;
        //}

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
            if (state == 1 && levelCreated == true) level1.DrawLevel(&window);
            else if (state == 2 && levelCreated == true) level2.DrawLevel(&window);
            //if (state == 1 || state == 2) ptr_levels->DrawLevel(&window);
            window.display();
        }
    }

    return 0;
}