#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include "Level1.h"
#include "Level2.h"

class Character : public sfp::PhysicsRectangle
{
private:
	sf::Texture m_characterT;
	sf::Clock m_clock;
	bool getObject;
	sf::Time lastTime;
	bool m_isAlive;
	bool hightVelocity;
  
public:
	Character();
	void forward();
	void backward();
	void jump();
	void jumpForward();
	void catchObject();
	void throwObject();
	void wait();
	int getPosX();
	int getPosY();
	void setIsAlive(bool isAlive);
	bool getIsAlive();
	void initCharacter();
	void updateCharacter(int& state, Level1* level1, Level2* level2);
};