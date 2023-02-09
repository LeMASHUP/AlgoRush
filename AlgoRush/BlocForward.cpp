#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlocForward.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"

#pragma execution_character_set( "utf-8" )


void BlocForward::action(Character* player) {
    player->forward();
    std::cout << "un caractère" << std::endl;
}

BlocForward::BlocForward()
{
    sf::Image image;
    if (!image.loadFromFile("assets/RIGHT.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_btexture.loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    setSize(Vector2f(80, 100));
    setTexture(&m_btexture);
}