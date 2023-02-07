#include "Menu.h"

Menu::Menu()
{
	// Images to load into texture
	sf::Image m_lahordeLogoI;
	sf::Image m_CILogoI;
	sf::Image m_playButtonI;
	sf::Image m_exitButtonI;
	sf::Image m_creditsButtonI;

	// Load and check font, images and textures
	if (!m_font.loadFromFile("assets/Assistant-Regular.ttf")) std::cout << "Error in loading the font" << std::endl;
	if (!m_lahordeLogoI.loadFromFile("assets/logo_lahorde_horizontal_HD.png")) std::cout << "Error in loading lahorde logo image" << std::endl;
	if (!m_lahordeLogoT.loadFromImage(m_lahordeLogoI)) std::cout << "Error in loading lahorde logo texture" << std::endl;
	if (!m_CILogoI.loadFromFile("assets/Logo_Clawed.png")) std::cout << "Error in loading CI logo image" << std::endl;
	if (!m_CILogoT.loadFromImage(m_CILogoI)) std::cout << "Error in loading CI logo texture" << std::endl;
	if (!m_playButtonI.loadFromFile("assets/launchMenu.png")) std::cout << "Error in loading play button image" << std::endl;
	if (!m_playButtonT.loadFromImage(m_playButtonI)) std::cout << "Error in loading play button texture" << std::endl;
	if (!m_exitButtonI.loadFromFile("assets/exitMenu.png")) std::cout << "Error in loading exit button image" << std::endl;
	if (!m_exitButtonT.loadFromImage(m_exitButtonI)) std::cout << "Error in loading exit button texture" << std::endl;
	if (!m_creditsButtonI.loadFromFile("assets/creditsMenu.png")) std::cout << "Error in loading credits button image" << std::endl;
	if (!m_creditsButtonT.loadFromImage(m_creditsButtonI)) std::cout << "Error in loading credits button texture" << std::endl;

	m_backgroundMenu.setSize(Vector2f(1600, 920));
	m_backgroundMenu.setFillColor(sf::Color::Black);
	m_backgroundMenu.setPosition(Vector2f(0, 0));

	m_lahordeLogo.setSize(Vector2f(500, 100));
	m_lahordeLogo.setTexture(&m_lahordeLogoT);
	m_lahordeLogo.setPosition(Vector2f(500, 150));

	m_CILogo.setSize(Vector2f(500, 125));
	m_CILogo.setTexture(&m_CILogoT);
	m_CILogo.setPosition(Vector2f(-10, 800));

	m_projectName.setFont(m_font);
	m_projectName.setString("Project 2022-I2");
	m_projectName.setCharacterSize(32);
	m_projectName.setFillColor(Color::Red);
	m_projectName.setStyle(sf::Text::Bold);
	m_projectName.setPosition(Vector2f(1350, 850));

	m_gameName.setFont(m_font);
	m_gameName.setString("ALGO RUSH");
	m_gameName.setCharacterSize(52);
	m_gameName.setFillColor(Color::Red);
	m_gameName.setStyle(sf::Text::Bold);
	m_gameName.setPosition(Vector2f(650, 300));

	m_playButton.setSize(Vector2f(225, 75));
	m_playButton.setTexture(&m_playButtonT);
	m_playButton.setOutlineThickness(1.0f);
	m_playButton.setOutlineColor(Color::White);
	m_playButton.setPosition(Vector2f(675, 400));

	m_exitButton.setSize(Vector2f(225, 75));
	m_exitButton.setTexture(&m_exitButtonT);
	m_exitButton.setOutlineThickness(1.0f);
	m_exitButton.setOutlineColor(Color::White);
	m_exitButton.setPosition(Vector2f(675, 550));

	m_creditsButton.setSize(Vector2f(225, 75));
	m_creditsButton.setTexture(&m_creditsButtonT);
	m_creditsButton.setOutlineThickness(1.0f);
	m_creditsButton.setOutlineColor(Color::White);
	m_creditsButton.setPosition(Vector2f(675, 700));
}

Menu::~Menu()
{
}

void Menu::drawMenu(sf::RenderWindow* window)
{
	window->draw(m_backgroundMenu);
	window->draw(m_lahordeLogo);
	window->draw(m_CILogo);
	window->draw(m_projectName);
	window->draw(m_gameName);
	window->draw(m_playButton);
	window->draw(m_exitButton);
	window->draw(m_creditsButton);
}

bool Menu::updateMenu(sf::RenderWindow* window, sf::Event* event, int& state)
{
	if (event->type == sf::Event::MouseButtonPressed && m_playButton.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y))
	{
		state = 1;
		return true;
	}
	if (event->type == sf::Event::MouseButtonPressed && m_exitButton.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y))
	{
		window->close();
		return true;
	}
	if (event->type == sf::Event::MouseButtonPressed && m_creditsButton.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y))
	{
		state = 6;
		return true;
	}
	return false;
}