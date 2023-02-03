#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

class Character : public sfp::PhysicsRectangle
{

private:

	sf::Texture m_sprite;
	sf::Clock m_clock;
	sf::Time lastTime;
	

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

};