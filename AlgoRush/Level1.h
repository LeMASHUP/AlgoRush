#pragma once

#include "Levels.h"

#include <iostream>
#include <string>

class Level1 : public Levels
{
private:
	sf::Texture m_backgroundLevel1T;
	sf::Texture m_floorLevel1T;
	sf::Texture m_bookPileT;
	sf::Texture m_DVDPileT;
	sf::Texture m_shelfT;
	sf::Texture m_exitLevel1T;

	sfp::PhysicsSprite m_backgroundLevel1;
	sfp::PhysicsSprite m_floorLevel1;
	sfp::PhysicsSprite m_bookPile;
	sfp::PhysicsSprite m_DVDPile;
	sfp::PhysicsSprite m_shelf;
	sfp::PhysicsSprite m_exitLevel1;
public:
	Level1(sfp::World* world);
	~Level1();
	void DrawLevel1(sf::RenderWindow* window);
};