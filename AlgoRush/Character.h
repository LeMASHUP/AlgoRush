#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

class Character : public sfp::PhysicsRectangle
{
private:
	sf::Texture m_sprite;
	sf::Clock m_clock;
	bool getObject;
	sf::Time lastTime;
	bool m_isAlive;
  
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
};