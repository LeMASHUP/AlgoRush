#include "GameOver.h"

GameOver::GameOver()
{
	// Images to load into texture
	sf::Image m_retryButtonI;
	sf::Image m_exitButtonI;
	sf::Image m_returnMenuButtonI;

	// Load and check font, images and textures
	if (!m_font.loadFromFile("assets/Assistant-Regular.ttf")) std::cout << "Error in loading the font" << std::endl;
	if (!m_retryButtonI.loadFromFile("assets/retryMenu.png")) std::cout << "Error in loading continue button image" << std::endl;
	if (!m_retryButtonT.loadFromImage(m_retryButtonI)) std::cout << "Error in loading continue button texture" << std::endl;
	if (!m_exitButtonI.loadFromFile("assets/exitMenu.png")) std::cout << "Error in loading exit button image" << std::endl;
	if (!m_exitButtonT.loadFromImage(m_exitButtonI)) std::cout << "Error in loading exit button texture" << std::endl;
	if (!m_returnMenuButtonI.loadFromFile("assets/returnMenu.png")) std::cout << "Error in loading return menu button image" << std::endl;
	if (!m_returnMenuButtonT.loadFromImage(m_returnMenuButtonI)) std::cout << "Error in loading return menu button texture" << std::endl;

	m_gameoverBackground.setSize(Vector2f(1600, 920));
	m_gameoverBackground.setFillColor(sf::Color::Black);
	m_gameoverBackground.setPosition(Vector2f(0, 0));

	m_gameoverText.setFont(m_font);
	m_gameoverText.setString("         Good try !\nWant to try again ?");
	m_gameoverText.setCharacterSize(52);
	m_gameoverText.setFillColor(Color::Red);
	m_gameoverText.setStyle(sf::Text::Bold);
	m_gameoverText.setPosition(Vector2f(600, 150));

	m_levelElapsedTimeText.setFont(m_font);
	m_levelElapsedTimeText.setCharacterSize(32);
	m_levelElapsedTimeText.setFillColor(Color::Red);
	m_levelElapsedTimeText.setStyle(sf::Text::Bold);
	m_levelElapsedTimeText.setPosition(Vector2f(150, 450));

	m_levelTriesText.setFont(m_font);
	m_levelTriesText.setCharacterSize(32);
	m_levelTriesText.setFillColor(Color::Red);
	m_levelTriesText.setStyle(sf::Text::Bold);
	m_levelTriesText.setPosition(Vector2f(150, 550));

	m_retryButton.setSize(Vector2f(225, 75));
	m_retryButton.setTexture(&m_retryButtonT);
	m_retryButton.setOutlineThickness(1.0f);
	m_retryButton.setOutlineColor(Color::White);
	m_retryButton.setPosition(Vector2f(875, 400));

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

GameOver::~GameOver()
{
}

void GameOver::drawGameOver(sf::RenderWindow* window)
{
	window->draw(m_gameoverBackground);
	window->draw(m_gameoverText);
	window->draw(m_levelElapsedTimeText);
	window->draw(m_levelTriesText);
	window->draw(m_retryButton);
	window->draw(m_exitButton);
	window->draw(m_returnMenuButton);
}

bool GameOver::updateGameOver(sf::RenderWindow* window, sf::Event* event, int& state, int& previousLevelState, bool& levelCreated)
{
	if (event->type == sf::Event::MouseButtonPressed && m_retryButton.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y))
	{
		levelCreated = false;
		state = previousLevelState;
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

void GameOver::setStringVariables(int& previousLevelState, Level1* level1, Level2* level2)
{
	if (previousLevelState == 1)
	{
		m_levelElapsedTimeString = "Elapsed time on level " + std::to_string(previousLevelState) + " : " + std::to_string(level1->getLevelsElapsedTime());
		m_levelElapsedTimeText.setString(m_levelElapsedTimeString);
		m_levelTriesString = "Number of tries on level " + std::to_string(previousLevelState) + " : " + std::to_string(level1->getLevelsTries());
		m_levelTriesText.setString(m_levelTriesString);
	}
	else if (previousLevelState == 2)
	{
		m_levelElapsedTimeString = "Elapsed time on level " + std::to_string(previousLevelState) + " : " + std::to_string(level2->getLevelsElapsedTime());
		m_levelElapsedTimeText.setString(m_levelElapsedTimeString);
		m_levelTriesString = "Number of tries on level " + std::to_string(previousLevelState) + " : " + std::to_string(level2->getLevelsTries());
		m_levelTriesText.setString(m_levelTriesString);
	}
}