#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

#include "Character.h"

int main()
{
    srand(time(0));

    Vector2f gravity(0, 1.0);
    sfp::World world(gravity);

    sf::Clock clock;
    sf::Time lastTime = clock.getElapsedTime();

    sf::RenderWindow window(sf::VideoMode(800, 600), "AlgoRush");

    sf::Event event;

    sfp::PhysicsRectangle floor;
    floor.setSize(Vector2f(800, 50));
    floor.setCenter(Vector2f(400, 575));
    floor.setStatic(true);
    world.AddPhysicsBody(floor);

    Character C;
    world.AddPhysicsBody(C);
   
    while (window.isOpen()) {
        
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
            window.draw(floor);
            std::cout << C.getPosX() << " " << C.getPosY() << endl;
            window.draw(C);
            window.display();
        }
    }

    return 0;
}