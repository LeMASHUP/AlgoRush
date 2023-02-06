#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <iostream>
#include "Object.h"

Object::Object(sf::Texture texture, Vector2f scale) : m_texture(texture), m_scale(scale), m_draw(true)
{
	this->setScale(m_scale);
	this->setTexture(m_texture);
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
