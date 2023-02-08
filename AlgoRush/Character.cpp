#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

Character::Character() : getObject(false)
{
	this->setSize(Vector2f(10, 20));
	this->setCenter(Vector2f(400, 450));
	this->setRestitution(0.15);

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
	this->setVelocity(Vector2f(0.1, -0.3));
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
