#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

class Button
{
private:
	sf::RectangleShape m_playButton;
	sf::RectangleShape m_exitButton;
	sf::RectangleShape m_nextLevelButton;
	sf::RectangleShape m_replayButton;
	sf::RectangleShape m_returnButton;
	sf::RectangleShape m_creditsButton;
public:
	Button();
	~Button();
	void PlayGame(int* state);
	void ExitGame(sf::RenderWindow* window);
	void NextLevel(int* state);
	void ReplayLevel(bool* initLevel);
	void ReturnMenu(int* state);
	void Credits(int* state);
};