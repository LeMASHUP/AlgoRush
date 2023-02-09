#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlocCatch.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"
//#include "Object.h"

#pragma execution_character_set( "utf-8" )


void BlocCatch::action(Character* player) {
    //if (player.collideWith(object).hasCollided)
    player->catchObject();
    //object.setIsDraw(false);
    std::cout << "un caractère" << std::endl;
}

BlocCatch::BlocCatch(/*Object* object*/) /*: m_object(object)*/
{
    sf::Image image;
    if (!image.loadFromFile("assets/CATCH.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_btexture.loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    this->setSize(Vector2f(80, 100));
    this->setTexture(&m_btexture);
}
