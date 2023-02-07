#include "Victory.h"

Victory::Victory()
{
	// Images to load into texture
	sf::Image m_continueButtonI;
	sf::Image m_exitButtonI;
	sf::Image m_returnMenuButtonI;

	// Load and check font, images and textures
	if (!m_font.loadFromFile("assets/Assistant-Regular.ttf")) std::cout << "Error in loading the font" << std::endl;
	if (!m_continueButtonI.loadFromFile("assets/continueMenu.png")) std::cout << "Error in loading continue button image" << std::endl;
	if (!m_continueButtonT.loadFromImage(m_continueButtonI)) std::cout << "Error in loading continue button texture" << std::endl;
	if (!m_exitButtonI.loadFromFile("assets/exitMenu.png")) std::cout << "Error in loading exit button image" << std::endl;
	if (!m_exitButtonT.loadFromImage(m_exitButtonI)) std::cout << "Error in loading exit button texture" << std::endl;
	if (!m_returnMenuButtonI.loadFromFile("assets/returnMenu.png")) std::cout << "Error in loading return menu button image" << std::endl;
	if (!m_returnMenuButtonT.loadFromImage(m_returnMenuButtonI)) std::cout << "Error in loading return menu button texture" << std::endl;

	m_victoryBackground.setSize(Vector2f(1600, 920));
	m_victoryBackground.setFillColor(sf::Color::Black);
	m_victoryBackground.setPosition(Vector2f(0, 0));

	m_victoryText.setFont(m_font);
	m_victoryText.setString("             Well done !\nReady for the next level ?");
	m_victoryText.setCharacterSize(52);
	m_victoryText.setFillColor(Color::Red);
	m_victoryText.setStyle(sf::Text::Bold);
	m_victoryText.setPosition(Vector2f(500, 150));

	m_levelElapsedTime.setFont(m_font);
	m_levelElapsedTime.setString("Elapsed time on level * : *");
	m_levelElapsedTime.setCharacterSize(40);
	m_levelElapsedTime.setFillColor(Color::Red);
	m_levelElapsedTime.setStyle(sf::Text::Bold);
	m_levelElapsedTime.setPosition(Vector2f(200, 450));

	m_levelTries.setFont(m_font);
	m_levelTries.setString("Number of tries on level * : *");
	m_levelTries.setCharacterSize(40);
	m_levelTries.setFillColor(Color::Red);
	m_levelTries.setStyle(sf::Text::Bold);
	m_levelTries.setPosition(Vector2f(200, 550));

	m_continueButton.setSize(Vector2f(225, 75));
	m_continueButton.setTexture(&m_continueButtonT);
	m_continueButton.setOutlineThickness(1.0f);
	m_continueButton.setOutlineColor(Color::White);
	m_continueButton.setPosition(Vector2f(875, 400));

	m_exitButton.setSize(Vector2f(225, 75));
	m_exitButton.setTexture(&m_exitButtonT);
	m_exitButton.setOutlineThickness(1.0f);
	m_exitButton.setOutlineColor(Color::White);
	m_exitButton.setPosition(Vector2f(875, 550));

	m_returnMenuButton.setSize(Vector2f(225, 75));
	m_returnMenuButton.setTexture(&m_returnMenuButtonT);
	m_returnMenuButton.setOutlineThickness(1.0f);
	m_returnMenuButton.setOutlineColor(Color::White);
	m_returnMenuButton.setPosition(Vector2f(875, 700));
}

Victory::~Victory()
{
}

void Victory::drawVictory(sf::RenderWindow* window)
{
	window->draw(m_victoryBackground);
	window->draw(m_victoryText);
	window->draw(m_levelElapsedTime);
	window->draw(m_levelTries);
	window->draw(m_continueButton);
	window->draw(m_exitButton);
	window->draw(m_returnMenuButton);
}

bool Victory::updateVictory(sf::RenderWindow* window, sf::Event* event, int& state)
{
	// keep state n-1
	if (event->type == sf::Event::MouseButtonPressed && m_continueButton.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y))
	{
		state += 1;
		return true;
	}
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
