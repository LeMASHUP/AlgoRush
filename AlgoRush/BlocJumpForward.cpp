#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlocJumpForward.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"

#pragma execution_character_set( "utf-8" )


void BlocJumpForward::action(Character* player) {
    player->jumpForward();
    std::cout << "un caract�re" << std::endl;
}

BlocJumpForward::BlocJumpForward()
{
    sf::Image image;
    if (!image.loadFromFile("assets/UPFORWARD.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_btexture.loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    setSize(Vector2f(80, 100));
    setTexture(&m_btexture);
}