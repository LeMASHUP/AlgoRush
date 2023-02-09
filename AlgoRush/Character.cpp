#include "Character.h"

Character::Character() : m_isAlive(true), getObject(false), hightVelocity(false)
{
	// Image to load into texture
	sf::Image m_characterI;

	// Load and check image and texture
	if (!m_characterI.loadFromFile("assets/character.png")) std::cout << "Error in loading character texture" << std::endl;
	if (!m_characterT.loadFromImage(m_characterI)) std::cout << "Error in loading character texture" << std::endl;

	this->setSize(Vector2f(50, 75));
	this->setTexture(&m_characterT);
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
	this->setVelocity(Vector2f(0, -0.7));
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

void Character::initCharacter()
{
	this->setCenter(Vector2f(200, 600));
	this->setVelocity(Vector2f(0, 0));
}

void Character::updateCharacter(int& state)
{
	if (!m_isAlive) {
		state = 5;
	}
	if (this->getVelocity().y > 0.8) {
		hightVelocity = true;
	}
	if (this->getVelocity().y < 0.1 && hightVelocity) {
		m_isAlive = false;
	}
}
