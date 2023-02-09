#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

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
#include "BlockManager.h"
#include "Program.h"
#include "Victory.h"

int main()
{
	int state = 0;
	int previousLevelState = 0;
	bool levelCreated = false;
	bool programInit = false;

	// To delete when win and loose condition working 
	bool test = false;
	//

	srand(time(0));

	Vector2f gravity(0, 1.0);
	sfp::World world(gravity);

	sf::Clock clock;
	sf::Time lastTime = clock.getElapsedTime();

	sf::RenderWindow window(sf::VideoMode(1600, 920), "AlgoRush");
	window.setFramerateLimit(60);

	sf::Event event;
  
	//Creation of levels, menus and character
	Menu* menu = new Menu();
	Credits* credits = new Credits();
	Level1* level1 = new Level1();
	Level2* level2 = new Level2();
	Character* character = new Character();
	Ennemies* ennemy = new Ennemies();
	GameOver* gameover = new GameOver();
	Victory* victory = new Victory();
	BlockManager* blockManager = new BlockManager(&world);
  Program* program = nullptr;

	while (window.isOpen()) {

		// To do whend the state change
		switch (state)
		{
		case 0:
		{
			level1->removePhysics(&world);
			level2->removePhysics(&world);
			ennemy->removePhysics(&world);
			world.RemovePhysicsBody(*character);
			break;
		}
		case 1:
		{
			if (levelCreated == false)
			{
				level2->removePhysics(&world);
				level1->addPhysics(&world);
				world.AddPhysicsBody(*character);
				ennemy->removePhysics(&world);
				previousLevelState = 1;
				levelCreated = true;
				blockManager.clearBlocInstructions();
				if (programInit) {
					delete program;
					programInit = false;
				}
				break;
			}
			if (blockManager.getStart() && !programInit) {
				program = new Program(blockManager.getBlockInstructions());
				programInit = true;
				program->init(&character);
			}
			else if (programInit)
			{
				program->update(&character);
			}
		}
		case 2:
		{
			if (levelCreated == false)
			{
				level1->removePhysics(&world);
				level2->addPhysics(&world);
				world.AddPhysicsBody(*character);
				ennemy->initEnnemies(650, 200);
				ennemy->addPhysics(&world);
				previousLevelState = 2;
				levelCreated = true;
				blockManager.clearBlocInstructions();
				if (programInit) {
					delete program;
					programInit = false;
				}
				break;
			}
			if (blockManager.getStart() && !programInit) 
			{
				program = new Program(blockManager.getBlockInstructions());
				programInit = true;
				program->init(&character);
			}
			else if (programInit) 
			{
				program->update(&character);
			}
			ennemy->updateEnnemies(&world, character, level2);
		}
		// Case 4 to delete when win and loose condition working
		case 5:
		{
			if (test == false)
			{
				gameover->setStringVariables(previousLevelState, level1, level2);
				test = true;
			}
			break;
		}
		//
		default:
			break;
		}

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();
			}

			// To do while the state is set
			switch (state)
			{
			case 0:
			{
				if (menu->updateMenu(&window, &event, state)) continue;
				break;
			}
			case 1:
			{
				blockManager->update(&event);
				break;
			}
			case 2:
			{
				blockManager->update(&event);
				break;
			}
			case 4:
			{
				if (victory->updateVictory(&window, &event, state, previousLevelState)) continue;
				break;
			}
			case 5:
			{
				if (gameover->updateGameOver(&window, &event, state, previousLevelState)) continue;
				break;
			}
			case 6:
			{
				if (credits->updateCredits(&window, &event, state)) continue;
				break;
			}
			default:
				break;
			}

		blockManager.update(&event);
		}

		sf::Time currentTime = clock.getElapsedTime();
		unsigned long elapsedMs = (currentTime - lastTime).asMilliseconds();

		if (elapsedMs > 0) {
			lastTime = currentTime;
			world.UpdatePhysics(elapsedMs);
			window.clear(sf::Color::Black);

			// To draw while the state is set
			switch (state)
			{
			case 0:
			{
				menu->drawMenu(&window);
				break;
			}
			case 1:
			{
				level1->drawLevel(&window);
				window.draw(*character);
				blockManager->draw(&window);
				break;
			}
			case 2:
			{
				level2->drawLevel(&window);
				window.draw(*character);
				ennemy->drawEnnemies(&window);
				blockManager->draw(&window);
				break;
			}
			case 4:
			{
				victory->drawVictory(&window);
				break;
			}
			case 5:
			{
				gameover->drawGameOver(&window);
				break;
			}
			case 6:
			{
				credits->drawCredits(&window);
				break;
			}
			default:
				break;
			}
			//world.VisualizeAllBounds(window);
			window.display();
		}
	}

	// Free the memory of every objects created
	delete(menu, credits, level1, level2, character, ennemy, gameover, victory, blockManager,program);
	return 0;
}