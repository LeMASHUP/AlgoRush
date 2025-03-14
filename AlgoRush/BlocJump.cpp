#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlocJump.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"

#pragma execution_character_set( "utf-8" )


void BlocJump::action(Character* player) {
	player->jump();
}

BlocJump::BlocJump()
{
    // Image to load into texture
    sf::Image image;

    // Load and check image and texture
    if (!image.loadFromFile("assets/UP.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_btexture.loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;

    setSize(Vector2f(80, 100));
    setTexture(&m_btexture);
}
