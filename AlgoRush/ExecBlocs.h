#pragma once

#include <SFML/Graphics.hpp>
#include "SFPhysics.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

class ExecBlocs : public sf::RectangleShape
{
protected:
	sf::Texture m_btexture;
	int m_iteration;
	sf::Text m_textIteration;
	sf::Font m_font;
public:
	virtual void action() = 0;
	ExecBlocs();
	void draw(sf:: RenderWindow* window);
	sf::Text& const getTextIteration();
	void setIteration(int iteration);
	int& const getIteration();
};