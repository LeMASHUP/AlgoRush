#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "ExecBlocs.h"

ExecBlocs::ExecBlocs()
{
	m_iteration = 1;
	if (!m_font.loadFromFile("assets/roboto.ttf")) {
		std::cout << "error could not load font" << std::endl;
	}
	m_textIteration.setFont(m_font);
	m_textIteration.setString("1");
}

void ExecBlocs::draw(sf::RenderWindow* window)
{
	window->draw(*this);
	window->draw(m_textIteration);
}

sf::Text& const ExecBlocs::getTextIteration()
{
	return m_textIteration;
}
