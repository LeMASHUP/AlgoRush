#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

Character::Character(sfp::World* world) : m_posX(200), m_posY(540)
{
	m_body.setSize(Vector2f(10, 20));
	m_body.setCenter(Vector2f(m_posX, m_posY));
	m_body.setRestitution(0);
	world->AddPhysicsBody(m_body);
}

void Character::forward()
{
	m_body.setVelocity(Vector2f(10, 0));
}

void Character::backward()
{
	m_body.setVelocity(Vector2f(-10, 0));
}

void Character::jump()
{
	m_body.setVelocity(Vector2f(0, -40));
}

void Character::jumpForward()
{
	m_body.setVelocity(Vector2f(10, -40));
}

void Character::catchObject()
{

}

void Character::throwObject()
{

}

void Character::wait()
{

}

void Character::draw(sf::RenderWindow* window)
{
	window->draw(m_body);
}

int Character::getPosX()
{
	return m_posX;
}

int Character::getPosy()
{
	return m_posY;
}
