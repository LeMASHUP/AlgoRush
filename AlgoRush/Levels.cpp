#include "Levels.h"

Levels::Levels()
{
}

sfp::PhysicsSprite Levels::getBackground()
{
	return m_background;
}

sfp::PhysicsSprite Levels::getFloor()
{
	return m_floor;
}

sfp::PhysicsSprite Levels::getExit()
{
	return m_exit;
}