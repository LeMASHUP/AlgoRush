#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlocJump.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"

//#include "Character.h"

#pragma execution_character_set( "utf-8" )


void action(/*Character player*/) {
	//player.jump();
}

BlocJump::BlocJump()
{
    m_iteration = 1;
    sf::Image image;
    if (!image.loadFromFile("assets/key.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_btexture.loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    this->setSize(Vector2f(75, 75));
    this->setTexture(&m_btexture);
}
