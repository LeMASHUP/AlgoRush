#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

#include "Character.h"
#include "Level1.h"
#include "Level2.h"

int main()
{
    int state = 2;

    srand(time(0));

    Vector2f gravity(0, 1.0);
    sfp::World world(gravity);

    sf::Clock clock;
    sf::Time lastTime = clock.getElapsedTime();

    Character C;
    world.AddPhysicsBody(C);

    sf::RenderWindow window(sf::VideoMode(1600, 920), "AlgoRush");
    window.setFramerateLimit(60);

    sf::Event event;

    //Creation of levels
    Level1 level1(&world);
    Level2 level2(&world);

    while (window.isOpen()) {

        switch (state)
        {
        case 1:
        {
            level2.RemovePhysics(&world);
            level1.AddPhysics(&world);
            break;
        }
        case 2:
        {
            level1.RemovePhysics(&world);
            level2.AddPhysics(&world);
            break;
        }
        default:
            break;
        }

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }

            if (event.key.code == sf::Keyboard::D) {

                C.forward();
            }

            if (event.key.code == sf::Keyboard::Q) {

                C.backward();
            }

            if (event.key.code == sf::Keyboard::Z) {


                C.jumpForward();
            }

            if (event.key.code == sf::Keyboard::Space) {

                C.jump();
            }
        }

        sf::Time currentTime = clock.getElapsedTime();
        unsigned long elapsedMs = (currentTime - lastTime).asMilliseconds();

        if (elapsedMs > 0) {
            lastTime = currentTime;
            world.UpdatePhysics(elapsedMs);
            window.clear(sf::Color::Black);
            window.draw(C);
            if (state == 1) level1.DrawLevel(&window);
            else if (state == 2) level2.DrawLevel(&window);
            //world.VisualizeAllBounds(window);
            window.display();
        }
    }

    return 0;
}