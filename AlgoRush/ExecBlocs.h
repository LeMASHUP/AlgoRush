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
public:
	virtual void action() = 0;
	ExecBlocs();
};