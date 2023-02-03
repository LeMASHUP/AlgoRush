#pragma once

#include "Levels.h"

class Level2 : public Levels
{
private:
	sf::Texture m_paperPlaneT;
	sf::Texture m_trashCanT;
	sf::Texture m_fireHydrantT;

	sfp::PhysicsSprite m_paperPlane;
	sfp::PhysicsSprite m_trashCan;
	sfp::PhysicsSprite m_fireHydrant;
public:
	Level2(sfp::World* world);
	~Level2();
	void DrawLevel(sf::RenderWindow* window) override;
};