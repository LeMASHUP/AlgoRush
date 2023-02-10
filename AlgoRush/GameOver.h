#pragma once

#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

#include "Level1.h"
#include "Level2.h"

#include <iostream>
#include <string>

class GameOver
{
private:
	// Loading font for texts
	sf::Font m_font;

	// Text objects
	sf::Text m_gameoverText;
	sf::Text m_levelElapsedTimeText;
	sf::Text m_levelTriesText;

	// String variable to put into sf::Text::toString()
	string m_levelElapsedTimeString;
	string m_levelTriesString;

	// Logos textures
	sf::Texture m_retryButtonT;
	sf::Texture m_exitButtonT;
	sf::Texture m_returnMenuButtonT;

	// Objects
	sf::RectangleShape m_gameoverBackground;
	sf::RectangleShape m_retryButton;
	sf::RectangleShape m_exitButton;
	sf::RectangleShape m_returnMenuButton;
public:
	GameOver();
	~GameOver();
	void drawGameOver(sf::RenderWindow* window);
	bool updateGameOver(sf::RenderWindow* window, sf::Event* event, int& state, int& previousLevelState, bool& levelCreated, bool& menuCreated, Character* character);
	void setStringVariables(int& previousLevelState, Level1* level1, Level2* level2);
};