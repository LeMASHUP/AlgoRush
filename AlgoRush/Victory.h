#pragma once

#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

#include <iostream>
#include <string>

class Victory
{
private:
	// Loading font for texts
	sf::Font m_font;

	// Text objects
	sf::Text m_victoryText;
	sf::Text m_levelElapsedTime;
	sf::Text m_levelTries;

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
	bool updateVictory(sf::RenderWindow* window, sf::Event* event, int& state);
};