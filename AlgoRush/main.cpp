#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

#include "Menu.h"
#include "Credits.h"
#include "Character.h"
#include "Level1.h"
#include "Level2.h"

int main()
{
	int state = 0;
	bool levelCreated = false;

	srand(time(0));

	Vector2f gravity(0, 1.0);
	sfp::World world(gravity);

	sf::Clock clock;
	sf::Time lastTime = clock.getElapsedTime();

	sf::RenderWindow window(sf::VideoMode(1600, 920), "AlgoRush");
	window.setFramerateLimit(60);

	sf::Event event;

	//Creation of levels and character
	Menu menu;
	Credits credits;
	Level1 level1(&world);
	Level2 level2(&world);
	Character character;

	while (window.isOpen()) {

		switch (state)
		{
		case 1:
		{
			if (levelCreated == false)
			{
				level2.RemovePhysics(&world);
				level1.AddPhysics(&world);
				world.AddPhysicsBody(character);
				levelCreated = true;
				break;
			}
		}
		case 2:
		{
			if (levelCreated == false)
			{
				level1.RemovePhysics(&world);
				level2.AddPhysics(&world);
				world.AddPhysicsBody(character);
				levelCreated = true;
				break;
			}
		}
		default:
			break;
		}

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();
			}
			if (menu.UpdateMenu(&window, &event, state))
				continue;

			if (credits.UpdateCredits(&window, &event, state))
				continue;

			if (event.key.code == sf::Keyboard::D) character.forward();
			if (event.key.code == sf::Keyboard::Q) character.backward();
			if (event.key.code == sf::Keyboard::Z) character.jumpForward();
			if (event.key.code == sf::Keyboard::Space) character.jump();
		}

		sf::Time currentTime = clock.getElapsedTime();
		unsigned long elapsedMs = (currentTime - lastTime).asMilliseconds();

		if (elapsedMs > 0) {
			lastTime = currentTime;
			world.UpdatePhysics(elapsedMs);
			window.clear(sf::Color::Black);
			switch (state)
			{
			case 0:
			{
				menu.DrawMenu(&window);
				break;
			}
			case 1:
			{
				level1.DrawLevel(&window);
				window.draw(character);
				break;
			}
			case 2:
			{
				level2.DrawLevel(&window);
				window.draw(character);
				break;
			}
			case 6:
			{
				credits.DrawCredits(&window);
				break;
			}
			default:
				break;
			}
			std::cout << state << std::endl;
			world.VisualizeAllBounds(window);
			window.display();
		}
	}

	return 0;
}