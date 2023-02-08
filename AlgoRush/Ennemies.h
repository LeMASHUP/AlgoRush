#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>
#include <string>

#include "Character.h"
#include "Level1.h"
#include "level2.h"

class Ennemies
{
private:
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