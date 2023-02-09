#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>

#include "Character.h"
#include "level2.h"

class Ennemies
{
private:
	// Ennemy object and texture
	sf::Texture m_ennemyT;
	sfp::PhysicsRectangle m_ennemy;

	float m_ennemyVelocity;
	bool m_isAlive;
public:
	Ennemies();
	~Ennemies();
	void initEnnemies(float pos_x, float pos_y);
	void drawEnnemies(sf::RenderWindow* window);
	void addPhysics(sfp::World* world);
	void removePhysics(sfp::World* world);
	void updateEnnemies(sfp::World* world, Character* character, Level2* level2);
};