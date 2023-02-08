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


void BlocJump::action(/*Character player*/) {
	//player.jump();
    std::cout << "un caractère" << std::endl;
}

BlocJump::BlocJump()
{
    sf::Image image;
    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_btexture.loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    setSize(Vector2f(75, 75));
    setTexture(&m_btexture);
}
