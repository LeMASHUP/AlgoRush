#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

class Levels
{
private:
	
protected:
	sf::Texture m_backgroundT;
	sf::Texture m_floorT;
	sf::Texture m_exitT;

	sfp::PhysicsSprite m_background;
	sfp::PhysicsSprite m_floor;
	sfp::PhysicsSprite m_exit;

	sfp::PhysicsRectangle m_blockBackground;
public:
	Levels();
	sfp::PhysicsSprite getFloor();
	sfp::PhysicsSprite getExit();
	virtual void DrawLevel(sf::RenderWindow* window) = 0;
};