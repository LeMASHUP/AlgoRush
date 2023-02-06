#include "SFPhysics.h"
#include "BlockManager.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdio>

BlocManager::BlocManager(sfp::World* world)
{
	for (int i = 0; i > 7; i++) {
		m_blockList[i].setSize(Vector2f (100, 100));
		m_blockList[i].setPosition(Vector2f(25+150*i, 200));
	}
}

void BlocManager::update(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
        for (int i = 0; i > 7; i++) {
            if (m_blockList[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                //m_blockList[0] correspond à BlocBackward, [1] = BlocCatch, [2] = BlocForward, [3] = BlocJump, [4] = BlocJumpForward, [5] = BlocThrow, [6] = BlocWait
                switch (i) {
                  case 0 :
                    {
                      BlocBackward BlocBackward;
                      BlocBackward.setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                      m_blockInstructions.push_back(BlocBackward);
                    }
                  case 1:
                  {
                      BlocCatch BlocCatch;
                      BlocCatch.setPosition(Vector2f(25+60*m_blockInstructions.size(), 200));
                      m_blockInstructions.push_back(BlocCatch);
                  }
                  case 2:
                  {
                      BlocForward BlocForward;
                      BlocForward.setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                      m_blockInstructions.push_back(BlocForward);
                  }
                  case 3:
                  {
                      BlocJump BlocJump;
                      BlocJump.setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                      m_blockInstructions.push_back(BlocJump);
                  }
                  case 4:
                  {
                      BlocJumpForward BlocJumpForward;
                      BlocJumpForward.setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                      m_blockInstructions.push_back(BlocJumpForward);
                  }
                  case 5:
                  {
                      BlocThrow BlocThrow;
                      BlocThrow.setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                      m_blockInstructions.push_back(BlocThrow);
                  }
                  case 6:
                  {
                      BlocWait BlocWait;
                      BlocWait.setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 200));
                      m_blockInstructions.push_back(BlocWait);
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

void BlocManager::draw(sf::RenderWindow* window)
{
    for (int i = 0; i < 7; i++) {
        window->draw(m_blockList[i]);
    }

    for (int i = 0; i < m_blockInstructions.size(); i++) {
        window->draw(m_blockInstructions.at(i));
    }
}
