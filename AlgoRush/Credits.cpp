#include "Credits.h"

Credits::Credits()
{
	// Images to load into texture
	sf::Image m_lahordeLogoI;
	sf::Image m_CILogoI;
	sf::Image m_exitButtonI;
	sf::Image m_returnMenuButtonI;

	// Load and check font, images and textures
	if (!m_font.loadFromFile("assets/Assistant-Regular.ttf")) std::cout << "Error in loading the font" << std::endl;
	if (!m_lahordeLogoI.loadFromFile("assets/logo_lahorde_horizontal_HD.png")) std::cout << "Error in loading lahorde logo image" << std::endl;
	if (!m_lahordeLogoT.loadFromImage(m_lahordeLogoI)) std::cout << "Error in loading lahorde logo texture" << std::endl;
	if (!m_CILogoI.loadFromFile("assets/Logo_Clawed.png")) std::cout << "Error in loading CI logo image" << std::endl;
	if (!m_CILogoT.loadFromImage(m_CILogoI)) std::cout << "Error in loading CI logo texture" << std::endl;
	if (!m_exitButtonI.loadFromFile("assets/exitMenu.png")) std::cout << "Error in loading exit button image" << std::endl;
	if (!m_exitButtonT.loadFromImage(m_exitButtonI)) std::cout << "Error in loading exit button texture" << std::endl;
	if (!m_returnMenuButtonI.loadFromFile("assets/returnMenu.png")) std::cout << "Error in loading return menu button image" << std::endl;
	if (!m_returnMenuButtonT.loadFromImage(m_returnMenuButtonI)) std::cout << "Error in loading return menu button texture" << std::endl;

	m_backgroundMenu.setSize(Vector2f(1600, 920));
	m_backgroundMenu.setFillColor(sf::Color::Black);
	m_backgroundMenu.setPosition(Vector2f(0, 0));

	m_lahordeLogo.setSize(Vector2f(500, 100));
	m_lahordeLogo.setTexture(&m_lahordeLogoT);
	m_lahordeLogo.setPosition(Vector2f(100, 100));

	m_CILogo.setSize(Vector2f(500, 125));
	m_CILogo.setTexture(&m_CILogoT);
	m_CILogo.setPosition(Vector2f(1100, 50));

	m_gameName.setFont(m_font);
	m_gameName.setString("ALGO RUSH");
	m_gameName.setCharacterSize(52);
	m_gameName.setFillColor(Color::Red);
	m_gameName.setStyle(sf::Text::Bold);
	m_gameName.setPosition(Vector2f(1225, 150));

	m_groupName.setFont(m_font);
	m_groupName.setString("PROJECT MANAGER\nZakaria DUTERTRE\n\n      PROGRAMER\nDoryan DECROIX\nXavier LE PAJOLEC\nGaspard CHATEAU");
	m_groupName.setCharacterSize(40);
	m_groupName.setFillColor(Color::Red);
	m_groupName.setStyle(sf::Text::Bold);
	m_groupName.setPosition(Vector2f(650, 325));

	m_exitButton.setSize(Vector2f(225, 75));
	m_exitButton.setTexture(&m_exitButtonT);
	m_exitButton.setOutlineThickness(1.0f);
	m_exitButton.setOutlineColor(Color::White);
	m_exitButton.setPosition(Vector2f(550, 800));

	m_returnMenuButton.setSize(Vector2f(225, 75));
	m_returnMenuButton.setTexture(&m_returnMenuButtonT);
	m_returnMenuButton.setOutlineThickness(1.0f);
	m_returnMenuButton.setOutlineColor(Color::White);
	m_returnMenuButton.setPosition(Vector2f(850, 800));
}

Credits::~Credits()
{
}

void Credits::DrawCredits(sf::RenderWindow* window)
{
	window->draw(m_backgroundMenu);
	window->draw(m_lahordeLogo);
	window->draw(m_CILogo);
	window->draw(m_gameName);
	window->draw(m_groupName);
	window->draw(m_exitButton);
	window->draw(m_returnMenuButton);
}

bool Credits::UpdateCredits(sf::RenderWindow* window, sf::Event* event, int& state)
{
	if (event->type == sf::Event::MouseButtonPressed && m_exitButton.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y))
	{
		window->close();
		return true;
	}
	if (event->type == sf::Event::MouseButtonPressed && m_returnMenuButton.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y))
	{
		state = 0;
		return true;
	}
	return false;
}