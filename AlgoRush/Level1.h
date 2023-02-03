#pragma once

#include "Levels.h"

class Level1 : public Levels
{
private:
	sf::Image m_bookPileI;
	sf::Image m_shelfI;
	sf::Image m_keyI;
	sf::Image m_DVDPileI;
	sf::Texture m_bookPileT;
	sf::Texture m_shelfT;
	sf::Texture m_keyT;
	sf::Texture m_DVDPileT;

	sfp::PhysicsRectangle m_bookPile;
	sfp::PhysicsRectangle m_shelf;
	sfp::PhysicsRectangle m_key;
	sfp::PhysicsRectangle m_DVDPile;
public:
	Level1(sfp::World* world);
	~Level1();
	void DrawLevel(sf::RenderWindow* window) override;
	void AddPhysics(sfp::World* world) override;
	void RemovePhysics(sfp::World* world) override;
};