#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

class Levels
{
private:
	
protected:
	sfp::PhysicsRectangle m_background;
	//sfp::PhysicsSprite m_background;
	sfp::PhysicsRectangle m_floor;
public:
	Levels();
	sfp::PhysicsRectangle getBackground();
	//sfp::PhysicsSprite getBackground();
	sfp::PhysicsRectangle getFloor();
	void DrawLevels(sf::RenderWindow* window);
};