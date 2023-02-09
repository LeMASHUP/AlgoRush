#pragma once

#include "Levels.h"

class Level2 : public Levels
{
private:
	// Level 2 textures to load and keep
	sf::Texture m_paperPlaneT;
	sf::Texture m_trashCanT;
	sf::Texture m_fireHydrantT;

	// Level 2 objects
	sfp::PhysicsRectangle m_paperPlane;
	sfp::PhysicsRectangle m_trashCan;
	sfp::PhysicsRectangle m_fireHydrant;
public:
	Level2(sfp::World* world);
	~Level2();
	void initLevels() override;
	void drawLevel(sf::RenderWindow* window) override;
	void addPhysics(sfp::World* world) override;
	void removePhysics(sfp::World* world) override;
	void setLevelsElapsedTime() override;
	void setLevelsTries(bool addTry) override;
	double getLevelsElapsedTime() override;
	int getLevelsTries() override;
	sfp::PhysicsRectangle& getTrashCan();
	sfp::PhysicsRectangle& getFireHydrant();
};