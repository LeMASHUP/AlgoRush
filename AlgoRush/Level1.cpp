#include "Level1.h"

Level1::Level1(sfp::World* world) : Levels()
{
	if (!m_backgroundT.loadFromFile("assets/backgroundLevel1.png")) std::cout << "Error in loading level 1 background texture" << std::endl;
	if (!m_floorT.loadFromFile("assets/floorLevel1.jpg")) std::cout << "Error in loading level 1 floor texture" << std::endl;
	if (!m_bookPileT.loadFromFile("assets/bookPile.png")) std::cout << "Error in loading book pile texture" << std::endl;
	if (!m_shelfT.loadFromFile("assets/shelf.png")) std::cout << "Error in loading shelf texture" << std::endl;
	if (!m_keyT.loadFromFile("assets/key.png")) std::cout << "Error in loading key texture" << std::endl;
	if (!m_DVDPileT.loadFromFile("assets/DVDPile.png")) std::cout << "Error in loading DVD pile texture" << std::endl;
	if (!m_exitT.loadFromFile("assets/exitLevel1.png")) std::cout << "Error in loading level 1 exit texture" << std::endl;
	
	m_background.setScale(Vector2f(1.2, 1.5));
	m_background.setCenter(Vector2f(0, 0));
	m_background.setTexture(m_backgroundT);
	m_background.setStatic(true);

	m_blockBackground.setSize(Vector2f(800, 100));
	m_blockBackground.setCenter(Vector2f(400, 550));
	m_blockBackground.setFillColor(sf::Color(50, 50, 50));
	m_blockBackground.setStatic(true);

	m_floor.setScale(Vector2f(1.5, 0.05));
	m_floor.setCenter(Vector2f(0, 500));
	m_floor.setTexture(m_floorT);
	m_floor.setStatic(true);
	world->AddPhysicsBody(m_floor);

	m_bookPile.setScale(Vector2f(0.2, 0.2));
	m_bookPile.setCenter(Vector2f(175, 425));
	m_bookPile.setTexture(m_bookPileT);
	m_bookPile.setStatic(true);
	world->AddPhysicsBody(m_bookPile);

	m_shelf.setScale(Vector2f(0.25, 0.5));
	m_shelf.setCenter(Vector2f(300, 350));
	m_shelf.setTexture(m_shelfT);
	m_shelf.setStatic(true);
	world->AddPhysicsBody(m_shelf);

	m_key.setScale(Vector2f(0.07, 0.07));
	m_key.setCenter(Vector2f(325, 315));
	m_key.setTexture(m_keyT);
	m_key.setStatic(true);

	m_DVDPile.setScale(Vector2f(0.5, 0.5));
	m_DVDPile.setCenter(Vector2f(450, 435));
	m_DVDPile.setTexture(m_DVDPileT);
	m_DVDPile.setStatic(true);
	world->AddPhysicsBody(m_DVDPile);

	m_exit.setScale(Vector2f(0.20, 0.3));
	m_exit.setCenter(Vector2f(700, 350));
	m_exit.setTexture(m_exitT);
	m_exit.setStatic(true);
	world->AddPhysicsBody(m_exit);
}

Level1::~Level1()
{
}

void Level1::DrawLevel(sf::RenderWindow* window)
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
