#include "Level2.h"

Level2::Level2(sfp::World* world) : Levels()
{
	m_background.setSize(Vector2f(800, 20));
	m_background.setCenter(Vector2f(400, 580));
	m_background.setStatic(true);

	m_floor.setSize(Vector2f(10, 600));
	m_floor.setCenter(Vector2f(25, 300));
	m_floor.setStatic(true);
	world->AddPhysicsBody(m_floor);
}

Level2::~Level2()
{
}

void Level2::DrawLevel2(sf::RenderWindow* window)
{
	window->draw(m_background);
	window->draw(m_floor);
	window->draw(m_paperPlane);
	window->draw(m_trashCan);
	window->draw(m_fireHydrant);
	window->draw(m_exit);
}
