#include "Character.h"

Character::Character() : m_isAlive(true), getObject(false)
{
	this->setSize(Vector2f(25, 50));
	this->setCenter(Vector2f(200, 300));
	this->setRestitution(0.15f);
}

void Character::forward()
{
	this->setVelocity(Vector2f(0.1, 0));
}

void Character::backward()
{
	this->setVelocity(Vector2f(-0.1, 0));
}

void Character::jump()
{
	this->setVelocity(Vector2f(0, -0.3));
}

void Character::jumpForward()
{
	this->setVelocity(Vector2f(0.1, -0.6));
}

void Character::catchObject()
{
	getObject = true;
}

void Character::throwObject()
{
	getObject = false;
}

void Character::wait()
{

}

int Character::getPosX()
{
	return this->getCenter().x;
}

int Character::getPosY()
{
	return this->getCenter().y;
}

void Character::setIsAlive(bool isAlive)
{
	m_isAlive = isAlive;
}

bool Character::getIsAlive()
{
	return m_isAlive;
}