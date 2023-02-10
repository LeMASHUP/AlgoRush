#include <iostream>
#include <cstdio>

#include "ExecBlocs.h"

ExecBlocs::ExecBlocs()
{
	m_iteration = 1;
	if (!m_font.loadFromFile("assets/Assistant-Regular.ttf")) {
		std::cout << "error could not load font" << std::endl;
	}
	m_textIteration.setFont(m_font);
	m_textIteration.setString("1");
	m_textIteration.setFillColor(Color(125, 125, 125));
	m_textIteration.setOutlineThickness(1);
	m_textIteration.setOutlineColor(Color::White);
	m_textIteration.setCharacterSize(35);
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

void ExecBlocs::setIteration(int iteration)
{
	m_iteration = iteration;
}

int& const ExecBlocs::getIteration()
{
	return m_iteration;
}
