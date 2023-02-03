#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

Character::Character(sfp::World* world)
{
	m_body.setSize(Vector2f(10, 20));
	m_body.setCenter(Vector2f(400, 100));
	m_body.setRestitution(0.05);
	world->AddPhysicsBody(m_body);
}

void Character::forward()
{
	m_body.setVelocity(Vector2f(0.1, 0));
}

void Character::backward()
{
	m_body.setVelocity(Vector2f(-0.1, 0));
}

void Character::jump()
{
	m_body.setVelocity(Vector2f(0, -0.3));
}

void Character::jumpForward()
{
	m_body.setVelocity(Vector2f(0.1, -0.3));
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
	return m_body.getCenter().x;
}

int Character::getPosY()
{
	return m_body.getCenter().y;
}
