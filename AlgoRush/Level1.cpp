#include "Level1.h"

Level1::Level1(sfp::World* world) : Levels()
{
	if (!m_backgroundLevel1T.loadFromFile("assets/backgroundLevel1.png")) std::cout << "Error in loading level 1 background texture" << std::endl;
	if (!m_floorLevel1T.loadFromFile("assets/floorLevel1.png")) std::cout << "Error in loading level 1 floor texture" << std::endl;
	if (!m_bookPileT.loadFromFile("assets/bookPile.png")) std::cout << "Error in loading book pile texture" << std::endl;
	if (!m_DVDPileT.loadFromFile("assets/DVDPile.png")) std::cout << "Error in loading DVD pile texture" << std::endl;
	if (!m_shelfT.loadFromFile("assets/shelf.png")) std::cout << "Error in loading shelf texture" << std::endl;
	if (!m_exitLevel1T.loadFromFile("assets/exitLevel1.png")) std::cout << "Error in loading level 1 exit texture" << std::endl;
	
	m_backgroundLevel1.setScale(Vector2f(1.0, 1.0));
	m_backgroundLevel1.setCenter(Vector2f(0, 0));
	m_backgroundLevel1.setTexture(m_backgroundLevel1T);
	m_backgroundLevel1.setStatic(true);

	m_floorLevel1.setScale(Vector2f(1.0, 1.0));
	m_floorLevel1.setCenter(Vector2f(400, 580));
	m_floorLevel1.setTexture(m_floorLevel1T);
	m_floorLevel1.setStatic(true);
	world->AddPhysicsBody(m_floorLevel1);

	m_bookPile.setScale(Vector2f(1.0, 1.0));
	m_bookPile.setCenter(Vector2f(150, 40));
	m_bookPile.setTexture(m_bookPileT);
	m_bookPile.setStatic(true);
	world->AddPhysicsBody(m_bookPile);

	m_DVDPile.setScale(Vector2f(1.0, 1.0));
	m_DVDPile.setCenter(Vector2f(450, 40));
	m_DVDPile.setTexture(m_DVDPileT);
	m_DVDPile.setStatic(true);
	world->AddPhysicsBody(m_DVDPile);

	m_shelf.setScale(Vector2f(1.0, 1.0));
	m_shelf.setCenter(Vector2f(300, 40));
	m_shelf.setTexture(m_shelfT);
	m_shelf.setStatic(true);
	world->AddPhysicsBody(m_shelf);

	m_exitLevel1.setScale(Vector2f(1.0, 1.0));
	m_exitLevel1.setCenter(Vector2f(550, 40));
	m_exitLevel1.setTexture(m_exitLevel1T);
	m_exitLevel1.setStatic(true);
	world->AddPhysicsBody(m_exitLevel1);
}

Level1::~Level1()
{

}

void Level1::DrawLevel1(sf::RenderWindow* window)
{
	window->draw(m_backgroundLevel1);
	window->draw(m_floorLevel1);
	window->draw(m_bookPile);
	window->draw(m_DVDPile);
	window->draw(m_shelf);
	window->draw(m_exitLevel1);
}
