#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <iostream>
#include "Object.h"

Object::Object(Vector2f scale) : m_scale(scale), m_draw(true)
{
	sf::Image image;
	if (!image.loadFromFile("assets/key.png")) std::cout << "Error in loading character image" << std::endl;
	if (!m_texture.loadFromImage(image)) std::cout << "Error in loading character texture" << std::endl;
	this->setTexture(&m_texture);
	this->setScale(m_scale);
}

void Object::throwObject()
{
	this->setVelocity(Vector2f(10, 20));
}

bool Object::getIsDraw()
{
	return m_draw;
}

void Object::setIsDraw(bool isDraw)
{
	m_draw = isDraw;
}
