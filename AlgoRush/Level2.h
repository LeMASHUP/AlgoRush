#pragma once

#include "Levels.h"

#include <iostream>
#include <string>

class Level2 : public Levels
{
private:
	sfp::PhysicsSprite m_paperPlane;
	sfp::PhysicsSprite m_trashCan;
	sfp::PhysicsSprite m_fireHydrant;
	sfp::PhysicsSprite m_exit;
public:
	Level2(sfp::World* world);
	~Level2();
	void DrawLevel2(sf::RenderWindow* window);
};