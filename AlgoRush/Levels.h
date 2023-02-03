#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

class Levels
{
private:
	
protected:
	sf::Image m_backgroundI;
	sf::Image m_floorI;
	sf::Image m_exitI;
	sf::Texture m_backgroundT;
	sf::Texture m_floorT;
	sf::Texture m_exitT;

	sfp::PhysicsRectangle m_background;
	sfp::PhysicsRectangle m_floor;
	sfp::PhysicsRectangle m_exit;
	sfp::PhysicsRectangle m_blockBackground;
public:
	Levels();
	sfp::PhysicsRectangle getFloor();
	sfp::PhysicsRectangle getExit();
	virtual void DrawLevel(sf::RenderWindow* window) = 0;
	virtual void AddPhysics(sfp::World* world) = 0;
	virtual void RemovePhysics(sfp::World* world) = 0;
};