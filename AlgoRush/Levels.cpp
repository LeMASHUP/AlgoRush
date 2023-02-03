#include "Levels.h"

Levels::Levels()
{
}

sfp::PhysicsRectangle Levels::getFloor()
{
	return m_floor;
}

sfp::PhysicsRectangle Levels::getExit()
{
	return m_exit;
}