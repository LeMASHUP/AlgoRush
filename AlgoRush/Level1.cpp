#include "Level1.h"

Level1::Level1() : Levels()
{
	// Images to load into texture
	sf::Image m_backgroundI;
	sf::Image m_floorI;
	sf::Image m_exitI;
	sf::Image m_bookPileI;
	sf::Image m_shelfI;
	sf::Image m_keyI;
	sf::Image m_DVDPileI;

	// Load and check images and textures
	if (!m_backgroundI.loadFromFile("assets/backgroundLevel1.png")) std::cout << "Error in loading level 1 background texture" << std::endl;
	if (!m_backgroundT.loadFromImage(m_backgroundI)) std::cout << "Error in loading level 1 background texture" << std::endl;
	if (!m_floorI.loadFromFile("assets/floorLevel1.jpg")) std::cout << "Error in loading level 1 floor texture" << std::endl;
	if (!m_floorT.loadFromImage(m_floorI)) std::cout << "Error in loading level 1 floor texture" << std::endl;
	if (!m_bookPileI.loadFromFile("assets/bookPile.png")) std::cout << "Error in loading book pile texture" << std::endl;
	if (!m_bookPileT.loadFromImage(m_bookPileI)) std::cout << "Error in loading book pile texture" << std::endl;
	if (!m_shelfI.loadFromFile("assets/shelf.png")) std::cout << "Error in loading shelf texture" << std::endl;
	if (!m_shelfT.loadFromImage(m_shelfI)) std::cout << "Error in loading shelf texture" << std::endl;
	if (!m_keyI.loadFromFile("assets/key.png")) std::cout << "Error in loading key texture" << std::endl;
	if (!m_keyT.loadFromImage(m_keyI)) std::cout << "Error in loading key texture" << std::endl;
	if (!m_DVDPileI.loadFromFile("assets/DVDPile.png")) std::cout << "Error in loading DVD pile texture" << std::endl;
	if (!m_DVDPileT.loadFromImage(m_DVDPileI)) std::cout << "Error in loading DVD pile texture" << std::endl;
	if (!m_exitI.loadFromFile("assets/exitLevel1.png")) std::cout << "Error in loading level 1 exit texture" << std::endl;
	if (!m_exitT.loadFromImage(m_exitI)) std::cout << "Error in loading level 1 exit texture" << std::endl;
	
	// Settings for objects
	m_background.setSize(Vector2f(1600, 840));
	m_background.setCenter(Vector2f(800, 250));
	m_background.setTexture(&m_backgroundT);
	m_background.setStatic(true);

	m_blockBackground.setSize(Vector2f(1600, 200));
	m_blockBackground.setCenter(Vector2f(800, 820));
	m_blockBackground.setFillColor(sf::Color(50, 50, 50));
	m_blockBackground.setStatic(true);

	m_floor.setSize(Vector2f(1600, 50));
	m_floor.setCenter(Vector2f(800, 695));
	m_floor.setTexture(&m_floorT);
	m_floor.setStatic(true);

	m_bookPile.setSize(Vector2f(150, 150));
	m_bookPile.setCenter(Vector2f(350, 610));
	m_bookPile.setTexture(&m_bookPileT);
	m_bookPile.setStatic(true);

	m_shelf.setSize(Vector2f(250, 50));
	m_shelf.setCenter(Vector2f(600, 375));
	m_shelf.setTexture(&m_shelfT);
	m_shelf.setStatic(true);

	m_key.setSize(Vector2f(75, 75));
	m_key.setCenter(Vector2f(600, 300));
	m_key.setTexture(&m_keyT);
	m_key.setStatic(true);

	m_DVDPile.setSize(Vector2f(150, 150));
	m_DVDPile.setCenter(Vector2f(800, 610));
	m_DVDPile.setTexture(&m_DVDPileT);
	m_DVDPile.setStatic(true);

	m_exit.setSize(Vector2f(150, 250));
	m_exit.setCenter(Vector2f(1400, 545));
	m_exit.setTexture(&m_exitT);
	m_exit.setStatic(true);
}

Level1::~Level1()
{
}

void Level1::initLevels()
{
	m_levelsBeginTime = levelsClock.getElapsedTime();
}

void Level1::drawLevel(sf::RenderWindow* window)
{
	window->draw(m_background);
	window->draw(m_blockBackground);
	window->draw(m_floor);
	window->draw(m_bookPile);
	window->draw(m_shelf);
	window->draw(m_key);
	window->draw(m_DVDPile);
	window->draw(m_exit);
}

void Level1::addPhysics(sfp::World* world)
{
	world->AddPhysicsBody(m_floor);
	world->AddPhysicsBody(m_bookPile);
	world->AddPhysicsBody(m_shelf);
	world->AddPhysicsBody(m_DVDPile);
	world->AddPhysicsBody(m_exit);
}

void Level1::removePhysics(sfp::World* world)
{
	world->RemovePhysicsBody(m_floor);
	world->RemovePhysicsBody(m_bookPile);
	world->RemovePhysicsBody(m_shelf);
	world->RemovePhysicsBody(m_DVDPile);
	world->RemovePhysicsBody(m_exit);
}

void Level1::setLevelsElapsedTime()
{
	m_levelsCurrentTime = levelsClock.getElapsedTime();
	m_levelsElapsedTime = (m_levelsCurrentTime - m_levelsBeginTime).asMilliseconds();
}

void Level1::setLevelsTries(bool addTry)
{
	if (addTry) m_levelsTries += 1;
	else m_levelsTries = 0;
}

double Level1::getLevelsElapsedTime()
{
	return m_levelsElapsedTime;
}

int Level1::getLevelsTries()
{
	return m_levelsTries;
}