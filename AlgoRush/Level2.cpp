#include "Level2.h"
#include "Character.h"

Level2::Level2() : Levels()
{
	// Images to load into texture
	sf::Image m_backgroundI;
	sf::Image m_floorI;
	sf::Image m_exitI;
	sf::Image m_paperPlaneI;
	sf::Image m_trashCanI;
	sf::Image m_fireHydrantI;

	// Load and check images and textures
	if (!m_backgroundI.loadFromFile("assets/backgroundLevel2.jpg")) std::cout << "Error in loading level 2 background texture" << std::endl;
	if (!m_backgroundT.loadFromImage(m_backgroundI)) std::cout << "Error in loading level 2 background texture" << std::endl;
	if (!m_floorI.loadFromFile("assets/floorLevel2.jpg")) std::cout << "Error in loading level 2 floor texture" << std::endl;
	if (!m_floorT.loadFromImage(m_floorI)) std::cout << "Error in loading level 2 floor texture" << std::endl;
	if (!m_paperPlaneI.loadFromFile("assets/paperPlane.png")) std::cout << "Error in loading paper plane texture" << std::endl;
	if (!m_paperPlaneT.loadFromImage(m_paperPlaneI)) std::cout << "Error in loading paper plane texture" << std::endl;
	if (!m_trashCanI.loadFromFile("assets/trashCan.png")) std::cout << "Error in loading trash can texture" << std::endl;
	if (!m_trashCanT.loadFromImage(m_trashCanI)) std::cout << "Error in loading trash can texture" << std::endl;
	if (!m_fireHydrantI.loadFromFile("assets/fireHydrant.png")) std::cout << "Error in loading fire Hydrant texture" << std::endl;
	if (!m_fireHydrantT.loadFromImage(m_fireHydrantI)) std::cout << "Error in loading fire Hydrant texture" << std::endl;
	if (!m_exitI.loadFromFile("assets/exitLevel2.png")) std::cout << "Error in loading level 2 exit texture" << std::endl;
	if (!m_exitT.loadFromImage(m_exitI)) std::cout << "Error in loading level 2 exit texture" << std::endl;

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

	m_paperPlane.setSize(Vector2f(50, 50));
	m_paperPlane.setCenter(Vector2f(300, 650));
	m_paperPlane.setTexture(&m_paperPlaneT);
	m_paperPlane.setStatic(true);

	m_trashCan.setSize(Vector2f(100, 150));
	m_trashCan.setCenter(Vector2f(550, 595));
	m_trashCan.setTexture(&m_trashCanT);
	m_trashCan.setStatic(true);

	m_fireHydrant.setSize(Vector2f(100, 150));
	m_fireHydrant.setCenter(Vector2f(1000, 595));
	m_fireHydrant.setTexture(&m_fireHydrantT);
	m_fireHydrant.setStatic(true);

	m_exit.setSize(Vector2f(200, 200));
	m_exit.setCenter(Vector2f(1500, 565));
	m_exit.setTexture(&m_exitT);
	m_exit.setStatic(true);

	m_levelsTries = 0;
}

Level2::~Level2()
{
}

void Level2::initLevels()
{
	setLevelsTries(true);
	m_levelsBeginTime = levelsClock.getElapsedTime();
}

void Level2::drawLevel(sf::RenderWindow* window)
{
	window->draw(m_background);
	window->draw(m_blockBackground);
	window->draw(m_floor);
	window->draw(m_paperPlane);
	window->draw(m_trashCan);
	window->draw(m_fireHydrant);
	window->draw(m_exit);
}

void Level2::addPhysics(sfp::World* world)
{
	world->AddPhysicsBody(m_floor);
	world->AddPhysicsBody(m_trashCan);
	world->AddPhysicsBody(m_fireHydrant);
	//world->AddPhysicsBody(m_exit);
}

void Level2::removePhysics(sfp::World* world)
{
	world->RemovePhysicsBody(m_floor);
	world->RemovePhysicsBody(m_trashCan);
	world->RemovePhysicsBody(m_fireHydrant);
	//world->RemovePhysicsBody(m_exit);
}

void Level2::setLevelsElapsedTime()
{
	m_levelsCurrentTime = levelsClock.getElapsedTime();
	m_levelsElapsedTime = (m_levelsCurrentTime - m_levelsBeginTime).asMilliseconds();
}

void Level2::setLevelsTries(bool addTry)
{
	if (addTry) m_levelsTries += 1;
	else m_levelsTries = 0;
}

int& const Level2::getLevelsElapsedTime()
{
	return m_levelsElapsedTime;
}

int& const Level2::getLevelsTries()
{
	return m_levelsTries;
}

sfp::PhysicsRectangle& Level2::getTrashCan()
{
	return m_trashCan;
}

sfp::PhysicsRectangle& Level2::getFireHydrant()
{
	return m_fireHydrant;
}

void Level2::isWin(sf::RenderWindow* window, Character* character, int& state)
{
	if (character->getCenter().x > m_exit.getCenter().x - m_exit.getSize().x / 2 && character->getCenter().x < m_exit.getCenter().x + m_exit.getSize().x / 2) {
		setLevelsElapsedTime();
		state = 4;
	}
}
