#include "Level1.h"

Level1::Level1(sfp::World* world) : Levels()
{
	m_background.setSize(Vector2f(800, 600));
	m_background.setCenter(Vector2f(400, 300));
	m_background.setFillColor(sf::Color(250, 100, 50));
	m_background.setStatic(true);

	m_floor.setSize(Vector2f(800, 10));
	m_floor.setCenter(Vector2f(400, 580));
	m_floor.setFillColor(sf::Color(50, 100, 250));
	m_floor.setStatic(true);
	world->AddPhysicsBody(m_floor);
}

Level1::~Level1()
{

}