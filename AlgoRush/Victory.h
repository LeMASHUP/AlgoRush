#pragma once

#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

#include "Level1.h"
#include "Level2.h"

#include <iostream>
#include <string>

class Victory
{
private:
	// Loading font for texts
	sf::Font m_font;

	// Text objects
	sf::Text m_victoryText;
	sf::Text m_levelElapsedTimeText;
	sf::Text m_levelTriesText;

	// String variable to put into sf::Text::toString()
	string m_levelElapsedTimeString;
	string m_levelTriesString;
	string m_victoryString;

	// Logos textures
	sf::Texture m_continueButtonT;
	sf::Texture m_exitButtonT;
	sf::Texture m_returnMenuButtonT;

	// Objects
	sf::RectangleShape m_victoryBackground;
	sf::RectangleShape m_continueButton;
	sf::RectangleShape m_exitButton;
	sf::RectangleShape m_returnMenuButton;
public:
	Victory();
	~Victory();
	void drawVictory(sf::RenderWindow* window);
	bool updateVictory(sf::RenderWindow* window, sf::Event* event, int& state, int& previousLevelState, bool& levelCreated);
	void setStringVariables(int& previousLevelState, Level1* level1, Level2* level2);
};