#include "Level2.h"

Level2::Level2(sfp::World* world) : Levels()
{
	if (!m_backgroundT.loadFromFile("assets/backgroundLevel2.jpg")) std::cout << "Error in loading level 2 background texture" << std::endl;
	if (!m_floorT.loadFromFile("assets/floorLevel2.jpg")) std::cout << "Error in loading level 2 floor texture" << std::endl;
	if (!m_paperPlaneT.loadFromFile("assets/paperPlane.png")) std::cout << "Error in loading paper plane texture" << std::endl;
	if (!m_trashCanT.loadFromFile("assets/trashCan.png")) std::cout << "Error in loading trash can texture" << std::endl;
	if (!m_fireHydrantT.loadFromFile("assets/fireHydrant.png")) std::cout << "Error in loading fire Hydrant texture" << std::endl;
	if (!m_exitT.loadFromFile("assets/exitLevel2.png")) std::cout << "Error in loading level 2 exit texture" << std::endl;

	m_background.setScale(Vector2f(1.6, 1.4));
	m_background.setCenter(Vector2f(0, 0));
	m_background.setTexture(m_backgroundT);
	m_background.setStatic(true);

	m_blockBackground.setSize(Vector2f(800, 100));
	m_blockBackground.setCenter(Vector2f(400, 550));
	m_blockBackground.setFillColor(sf::Color(50, 50, 50));
	m_blockBackground.setStatic(true);

	m_floor.setScale(Vector2f(1.5, 0.025));
	m_floor.setCenter(Vector2f(0, 467));
	m_floor.setTexture(m_floorT);
	m_floor.setStatic(true);
	world->AddPhysicsBody(m_floor);

	m_paperPlane.setScale(Vector2f(0.1, 0.1));
	m_paperPlane.setCenter(Vector2f(150, 445));
	m_paperPlane.setTexture(m_paperPlaneT);
	m_paperPlane.setStatic(true);

	m_trashCan.setScale(Vector2f(0.1, 0.1));
	m_trashCan.setCenter(Vector2f(250, 415));
	m_trashCan.setTexture(m_trashCanT);
	m_trashCan.setStatic(true);
	world->AddPhysicsBody(m_trashCan);

	m_fireHydrant.setScale(Vector2f(0.25, 0.25));
	m_fireHydrant.setCenter(Vector2f(425, 410));
	m_fireHydrant.setTexture(m_fireHydrantT);
	m_fireHydrant.setStatic(true);
	world->AddPhysicsBody(m_fireHydrant);

	m_exit.setScale(Vector2f(0.20, 0.3));
	m_exit.setCenter(Vector2f(700, 325));
	m_exit.setTexture(m_exitT);
	m_exit.setStatic(true);
	world->AddPhysicsBody(m_exit);
}

Level2::~Level2()
{
}

void Level2::DrawLevel(sf::RenderWindow* window)
{
	window->draw(m_background);
	window->draw(m_blockBackground);
	window->draw(m_floor);
	window->draw(m_paperPlane);
	window->draw(m_trashCan);
	window->draw(m_fireHydrant);
	window->draw(m_exit);
}
