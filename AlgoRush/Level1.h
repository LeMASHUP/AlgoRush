#pragma once

#include "Levels.h"

class Level1 : public Levels
{
private:
	sf::Texture m_bookPileT;
	sf::Texture m_shelfT;
	sf::Texture m_keyT;
	sf::Texture m_DVDPileT;

	sfp::PhysicsSprite m_bookPile;
	sfp::PhysicsSprite m_shelf;
	sfp::PhysicsSprite m_key;
	sfp::PhysicsSprite m_DVDPile;
public:
	Level1(sfp::World* world);
	~Level1();
	void DrawLevel(sf::RenderWindow* window) override;
};