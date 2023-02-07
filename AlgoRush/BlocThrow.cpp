#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlocThrow.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"

//#include "Character.h"

#pragma execution_character_set( "utf-8" )


void BlocThrow::action(/*Character player*/) {
    //player.throwObject();
    //object.setIsDraw(true);
    //object.throwObject();
    std::cout << "un caractère" << std::endl;
}

BlocThrow::BlocThrow()
{
    sf::Image image;
    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_btexture.loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    setSize(Vector2f(75, 75));
    setTexture(&m_btexture);
}