#include "SFPhysics.h"
#include "BlockManager.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdio>

BlockManager::BlockManager(sfp::World* world)
{
	for (int i = 0; i < 8; i++) {
		m_blockList[i].setSize(Vector2f (100, 100));
		m_blockList[i].setPosition(Vector2f(25+150*i, 200));
	}
}

void BlockManager::update(sf::Event* event)
{
    if (event->type == sf::Event::MouseButtonPressed) {
        for (int i = 0; i < 8; i++) {
            if (m_blockList[i].getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y)) {
                //m_blockList[0] correspond à BlocBackward, [1] = BlocCatch, [2] = BlocForward, [3] = BlocJump, [4] = BlocJumpForward, [5] = BlocThrow, [6] = BlocWait
                switch (i) {
                  case 0 :
                    {
                      m_blockInstructions.push_back(new BlocBackward);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 1" << std::endl;
                      break;
                    }
                  case 1:
                  {
                      m_blockInstructions.push_back(new BlocCatch);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 2" << std::endl;
                      break;
                  }
                  case 2:
                  {
                      m_blockInstructions.push_back(new BlocForward);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 3" << std::endl;
                      break;
                  }
                  case 3:
                  {
                      m_blockInstructions.push_back(new BlocJump);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 4" << std::endl;
                      break;
                  }
                  case 4:
                  {
                      m_blockInstructions.push_back(new BlocJumpForward);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 5" << std::endl;
                      break;
                  }
                  case 5:
                  {
                      m_blockInstructions.push_back(new BlocThrow);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 6" << std::endl;
                      break;
                  }
                  case 6:
                  {
                      m_blockInstructions.push_back(new BlocWait);
                      m_blockInstructions.back()->setPosition(Vector2f(25 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 7" << std::endl;
                      break;
                  }
                  case 7:
                  {
                      std::cout << "Delete" << std::endl;
                      delete m_blockInstructions.back();
                      m_blockInstructions.pop_back();
                      std::cout << "Deleted" << std::endl;
                      break;
                  }
                  default: 
                  {
                      break;
                  }
                }
            }
        }
        for (int i = 0; i < m_blockInstructions.size(); i++) {
            if (m_blockInstructions.at(i)->getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y)) {
                std::cout << "Modified" << std::endl;

                break;
            }
        }
    }
}

void BlockManager::draw(sf::RenderWindow* window)
{
    for (int i = 0; i < 8; i++) {
        window->draw(m_blockList[i]);
    }

    for (int i = 0; i < m_blockInstructions.size(); i++) {
        m_blockInstructions.at(i)->getTextIteration().setPosition(m_blockInstructions.at(i)->getPosition().x, m_blockInstructions.at(i)->getPosition().y);
        m_blockInstructions.at(i)->draw(window);
    }
}
