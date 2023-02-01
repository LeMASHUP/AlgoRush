#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

class Levels
{
private:
	
protected:
	std::string m_backgroundSprite;
	std::string m_floorSprite;
	sfp::PhysicsRectangle m_background;
	sfp::PhysicsRectangle m_floor;
public:
	Levels();
	sfp::PhysicsRectangle getBackground();
	sfp::PhysicsRectangle getFloor();
	void DrawLevels(sf::RenderWindow* window);
};