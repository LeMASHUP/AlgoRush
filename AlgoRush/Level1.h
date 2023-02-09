#pragma once

#include "Levels.h"

class Level1 : public Levels
{
private:
	// Level 1 textures to load and keep
	sf::Texture m_bookPileT;
	sf::Texture m_shelfT;
	sf::Texture m_keyT;
	sf::Texture m_DVDPileT;

	// Level 1 objects
	sfp::PhysicsRectangle m_bookPile;
	sfp::PhysicsRectangle m_shelf;
	sfp::PhysicsRectangle m_key;
	sfp::PhysicsRectangle m_DVDPile;
public:
	Level1();
	~Level1();
	void initLevels() override;
	void drawLevel(sf::RenderWindow* window) override;
	void addPhysics(sfp::World* world) override;
	void removePhysics(sfp::World* world) override;
	void setLevelsElapsedTime() override;
	void setLevelsTries(bool addTry) override;
	double getLevelsElapsedTime() override;
	int getLevelsTries() override;
};