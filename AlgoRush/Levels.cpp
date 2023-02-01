#include "Levels.h"

Levels::Levels()
{
}

sfp::PhysicsRectangle Levels::getBackground()
{
	return m_background;
}

//sfp::PhysicsSprite Levels::getBackground()
//{
//	return m_background;
//}

sfp::PhysicsRectangle Levels::getFloor()
{
	return m_floor;
}

void Levels::DrawLevels(sf::RenderWindow* window)
{
	window->draw(m_background);
	window->draw(m_floor);
}