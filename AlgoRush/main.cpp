#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlockManager.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <cstdio>

#include "Menu.h"
#include "GameOver.h"
#include "Credits.h"
#include "Character.h"
#include "Ennemies.h"
#include "Level1.h"
#include "Level2.h"
#include "Victory.h"


int main()
{
	int state = 5;
	int previousLevelState = 1;
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
	GameOver gameover;
	Victory victory;
	BlockManager BlockManager(&world);

	while (window.isOpen()) {

		switch (state)
		{
		case 0:
		{
			level1.removePhysics(&world);
			level2.removePhysics(&world);
			ennemy.removePhysics(&world);
			world.RemovePhysicsBody(character);
			break;
		}
		case 1:
		{
			if (levelCreated == false)
			{
				level2.removePhysics(&world);
				level1.addPhysics(&world);
				world.AddPhysicsBody(character);
				ennemy.removePhysics(&world);
				previousLevelState = 1;
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
				previousLevelState = 2;
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

			switch (state)
			{
			case 0:
			{
				if (menu.updateMenu(&window, &event, state)) continue;
				break;
			}
			case 4:
			{
				if (victory.updateVictory(&window, &event, state, previousLevelState)) continue;
				break;
			}
			case 5:
			{
				if (gameover.updateGameOver(&window, &event, state, previousLevelState)) continue;
				break;
			}
			case 6:
			{
				if (credits.updateCredits(&window, &event, state)) continue;
				break;
			}
			default:
				break;
			}

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
			case 4:
			{
				victory.drawVictory(&window);
				break;
			}
			case 5:
			{
				gameover.drawGameOver(&window);
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