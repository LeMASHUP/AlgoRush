#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"

#include <iostream>

class Levels
{
protected:
	// Elapsed time since start of a level and number of tries
	sf::Clock levelsClock;
	sf::Time m_levelsBeginTime;
	sf::Time m_levelsCurrentTime;
	double m_levelsElapsedTime;
	int m_levelsTries;

	// Texture for all levels to load and keep
	sf::Texture m_backgroundT;
	sf::Texture m_floorT;
	sf::Texture m_exitT;

	// Objects for all levels
	sfp::PhysicsRectangle m_background;
	sfp::PhysicsRectangle m_floor;
	sfp::PhysicsRectangle m_exit;
	sfp::PhysicsRectangle m_blockBackground;
public:
	Levels();
	virtual void initLevels() = 0;
	virtual void drawLevel(sf::RenderWindow* window) = 0;
	virtual void addPhysics(sfp::World* world) = 0;
	virtual void removePhysics(sfp::World* world) = 0;
	virtual void setLevelsElapsedTime() = 0;
	virtual void setLevelsTries(bool addTry) = 0;
	virtual double getLevelsElapsedTime() = 0;
	virtual int getLevelsTries() = 0;
};