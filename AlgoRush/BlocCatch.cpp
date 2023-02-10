#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlocCatch.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"

#pragma execution_character_set( "utf-8" )


void BlocCatch::action(Character* player) {
    //if (player.collideWith(object).hasCollided)
    player->catchObject();
    //object.setIsDraw(false);
}

BlocCatch::BlocCatch(/*Object* object*/) /*: m_object(object)*/
{
    // Image to load into texture
    sf::Image image;

    // Load and check image and texture
    if (!image.loadFromFile("assets/CATCH.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_btexture.loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;

    this->setSize(Vector2f(80, 100));
    this->setTexture(&m_btexture);
}
