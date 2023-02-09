#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

class Credits
{
private:
	// Loading font for texts
	sf::Font m_font;

	// Text objects
	sf::Text m_gameName;
	sf::Text m_groupName;

	// Logos and buttons textures
	sf::Texture m_lahordeLogoT;
	sf::Texture m_CILogoT;
	sf::Texture m_exitButtonT;
	sf::Texture m_returnMenuButtonT;

	// Objects
	sf::RectangleShape m_backgroundMenu;
	sf::RectangleShape m_lahordeLogo;
	sf::RectangleShape m_CILogo;
	sf::RectangleShape m_exitButton;
	sf::RectangleShape m_returnMenuButton;
public:
	Credits();
	~Credits();
	void drawCredits(sf::RenderWindow* window);
	bool updateCredits(sf::RenderWindow* window, sf::Event* event, int& state);
};

