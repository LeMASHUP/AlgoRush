#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

class Menu
{
private:
	// Loading font for texts
	sf::Font m_font;

	// Text objects
	sf::Text m_gameName;
	sf::Text m_projectName;

	// Logos textures
	sf::Texture m_lahordeLogoT;
	sf::Texture m_CILogoT;
	sf::Texture m_playButtonT;
	sf::Texture m_exitButtonT;
	sf::Texture m_creditsButtonT;

	// Objects
	sf::RectangleShape m_backgroundMenu;
	sf::RectangleShape m_lahordeLogo;
	sf::RectangleShape m_CILogo;
	sf::RectangleShape m_playButton;
	sf::RectangleShape m_exitButton;
	sf::RectangleShape m_creditsButton;
public:
	Menu();
	~Menu();
	void drawMenu(sf::RenderWindow* window);
	bool updateMenu(sf::RenderWindow* window, sf::Event* event, int& state);
};