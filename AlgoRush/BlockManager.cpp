#include "SFPhysics.h"
#include "BlockManager.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdio>

BlockManager::BlockManager(sfp::World* world)
{
	for (int i = 0; i > 7; i++) {
		m_blockList[i].setSize(Vector2f (100, 100));
		m_blockList[i].setPosition(Vector2f(25+150*i, 200));
	}
}

void BlockManager::update(sf::Event* event)
{
    if (event->type == sf::Event::MouseButtonPressed)
        for (int i = 0; i > 7; i++) {
            if (m_blockList[i].getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y)) {
                //m_blockList[0] correspond à BlocBackward, [1] = BlocCatch, [2] = BlocForward, [3] = BlocJump, [4] = BlocJumpForward, [5] = BlocThrow, [6] = BlocWait
                switch (i) {
                  case 0 :
                    {
                      m_blockInstructions.push_back(new BlocBackward);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                    }
                  case 1:
                  {
                      m_blockInstructions.push_back(new BlocCatch);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                  }
                  case 2:
                  {
                      m_blockInstructions.push_back(new BlocForward);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                  }
                  case 3:
                  {
                      m_blockInstructions.push_back(new BlocJump);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                  }
                  case 4:
                  {
                      m_blockInstructions.push_back(new BlocJumpForward);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                  }
                  case 5:
                  {
                      m_blockInstructions.push_back(new BlocThrow);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                  }
                  case 6:
                  {
                      m_blockInstructions.push_back(new BlocWait);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                  }
                  default: 
                  {
                      break;
                  }
                }
                break;
            }
        }
}

void BlockManager::draw(sf::RenderWindow* window)
{
    for (int i = 0; i < 7; i++) {
        window->draw(m_blockList[i]);
    }

    for (int i = 0; i < m_blockInstructions.size(); i++) {
        window->draw(*m_blockInstructions.at(i));
    }
}
