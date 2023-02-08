#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlockManager.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <cstdio>

#include "Menu.h"
#include "Credits.h"
#include "Character.h"
#include "Ennemies.h"
#include "Level1.h"
#include "Level2.h"


int main()
{
	int state = 2;
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
	Ennemies ennemy;
  BlockManager BlockManager(&world);

	while (window.isOpen()) {

		switch (state)
		{
		case 1:
		{
			if (levelCreated == false)
			{
				level2.removePhysics(&world);
				level1.addPhysics(&world);
				world.AddPhysicsBody(character);
				ennemy.removePhysics(&world);
				levelCreated = true;
				break;
			}
		}
		case 2:
		{
			if (levelCreated == false)
			{
				level1.removePhysics(&world);
				level2.addPhysics(&world);
				world.AddPhysicsBody(character);
				ennemy.initEnnemies(650, 200);
				ennemy.addPhysics(&world);
				levelCreated = true;
				break;
			}
			ennemy.updateEnnemies(&world, &character, &level2);
		}
		default:
			break;
		}

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();
			}
			if (menu.updateMenu(&window, &event, state))
				continue;

			if (credits.updateCredits(&window, &event, state))
				continue;

			if (event.key.code == sf::Keyboard::D) character.forward();
			if (event.key.code == sf::Keyboard::Q) character.backward();
			if (event.key.code == sf::Keyboard::Z) character.jumpForward();
			if (event.key.code == sf::Keyboard::Space) character.jump();
      
      BlockManager.update(&event);
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
				menu.drawMenu(&window);
				break;
			}
			case 1:
			{
				level1.drawLevel(&window);
				window.draw(character);
				break;
			}
			case 2:
			{
				level2.drawLevel(&window);
				window.draw(character);
				ennemy.drawEnnemies(&window);
				break;
			}
			case 6:
			{
				credits.drawCredits(&window);
				break;
			}
			default:
				break;
			}
      BlockManager.draw(&window);
			//world.VisualizeAllBounds(window);
			window.display();
		}
	}

	return 0;
}