#include "SFPhysics.h"
#include "BlockManager.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstdio>

BlockManager::BlockManager(sfp::World* world) :m_start(false)
{
    m_select = -1;
	for (int i = 0; i < 8; i++) {
		m_blockList[i].setSize(Vector2f (100, 100));
		m_blockList[i].setPosition(Vector2f(25+150*i, 200));
	}
    m_blockList[8].setSize(Vector2f(100, 100));
    m_blockList[8].setPosition(Vector2f(1500, 500));
    m_startBloc.setSize(Vector2f(75, 75));
    m_startBloc.setPosition(Vector2f(85, 500));

    sf::Image image;
    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_blocTexture[0].loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_blockList[0].setTexture(&m_blocTexture[0]);

    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_blocTexture[1].loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_blockList[1].setTexture(&m_blocTexture[1]);

    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_blocTexture[2].loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_blockList[2].setTexture(&m_blocTexture[2]);

    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_blocTexture[3].loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_blockList[3].setTexture(&m_blocTexture[3]);

    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_blocTexture[4].loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_blockList[4].setTexture(&m_blocTexture[4]);

    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_blocTexture[5].loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_blockList[5].setTexture(&m_blocTexture[5]);

    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_blocTexture[6].loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_blockList[6].setTexture(&m_blocTexture[6]);

    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_blocTexture[7].loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_blockList[7].setTexture(&m_blocTexture[7]);

    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_blocTexture[8].loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_blockList[8].setTexture(&m_blocTexture[8]);

    if (!image.loadFromFile("assets/block.png")) std::cout << "Error in loading blocup texture" << std::endl;
    if (!m_startTexture.loadFromImage(image)) std::cout << "Error in loading blocup texture" << std::endl;
    m_startBloc.setTexture(&m_startTexture);
}

void BlockManager::update(sf::Event* event)
{
    if (event->type == sf::Event::MouseButtonPressed && !m_start) {
        if (m_select >= 0) {
            m_select = -1;
        }

        for (int i = 0; i < 9; i++) {
            if (m_blockList[i].getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y)) {
                //m_blockList[0] correspond à BlocBackward, [1] = BlocCatch, [2] = BlocForward, [3] = BlocJump, [4] = BlocJumpForward, [5] = BlocThrow, [6] = BlocWait
                switch (i) {
                  case 0 :
                    {
                      m_blockInstructions.push_back(new BlocBackward);
                      m_blockInstructions.back()->setPosition(Vector2f(85 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 1" << std::endl;
                      break;
                    }
                  case 1:
                  {
                      m_blockInstructions.push_back(new BlocCatch);
                      m_blockInstructions.back()->setPosition(Vector2f(85 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 2" << std::endl;
                      break;
                  }
                  case 2:
                  {
                      m_blockInstructions.push_back(new BlocForward);
                      m_blockInstructions.back()->setPosition(Vector2f(85 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 3" << std::endl;
                      break;
                  }
                  case 3:
                  {
                      m_blockInstructions.push_back(new BlocJump);
                      m_blockInstructions.back()->setPosition(Vector2f(85 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 4" << std::endl;
                      break;
                  }
                  case 4:
                  {
                      m_blockInstructions.push_back(new BlocJumpForward);
                      m_blockInstructions.back()->setPosition(Vector2f(85 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 5" << std::endl;
                      break;
                  }
                  case 5:
                  {
                      m_blockInstructions.push_back(new BlocThrow);
                      m_blockInstructions.back()->setPosition(Vector2f(85 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 6" << std::endl;
                      break;
                  }
                  case 6:
                  {
                      m_blockInstructions.push_back(new BlocWait);
                      m_blockInstructions.back()->setPosition(Vector2f(85 + 60 * m_blockInstructions.size(), 500));
                      std::cout << "Print 7" << std::endl;
                      break;
                  }
                  case 7:
                  {
                      if (m_blockInstructions.size() > 0) {
                        std::cout << "Delete" << std::endl;
                        delete m_blockInstructions.back();
                        m_blockInstructions.pop_back();
                        std::cout << "Deleted" << std::endl;
                      }
                      break;
                  }
                  case 8: 
                  {
                      if (m_blockInstructions.size() > 0) {
                          m_start = true;
                          //
                      }
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
                m_select = i;
                std::cout << m_select << std::endl;
                break;
            }
        }
    }
    else if (event-> type == sf::Event::KeyPressed && !m_start){

        if (event->key.code == sf::Keyboard::Numpad0 && m_select>=0) {
            int iteration=m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration *= 10;
            }
            else if (iteration < 1) {
                iteration = 0;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string (iteration));
        }

        else if (event->key.code == sf::Keyboard::Numpad1 && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration = (iteration*10) + 1;
            }
            else if (iteration < 1) {
                iteration = 1;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
        }

        else if (event->key.code == sf::Keyboard::Numpad2 && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration = (iteration*10) + 2;
            }
            else if (iteration < 1) {
                iteration = 2;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
        }

        else if (event->key.code == sf::Keyboard::Numpad3 && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration = (iteration * 10) + 3;
            }
            else if (iteration < 1) {
                iteration = 3;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
        }

        else if (event->key.code == sf::Keyboard::Numpad4 && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration = (iteration * 10) + 4;
            }
            else if (iteration < 1) {
                iteration = 4;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
        }

        else if (event->key.code == sf::Keyboard::Numpad5 && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration = (iteration * 10) + 5;
            }
            else if (iteration < 1) {
                iteration = 5;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
        }

        else if (event->key.code == sf::Keyboard::Numpad6 && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration = (iteration * 10) + 6;
            }
            else if (iteration < 1) {
                iteration = 6;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
        }

        else if (event->key.code == sf::Keyboard::Numpad7 && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration = (iteration * 10) + 7;
            }
            else if (iteration < 1) {
                iteration = 7;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
        }

        else if (event->key.code == sf::Keyboard::Numpad8 && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration = (iteration * 10) + 8;
            }
            else if (iteration < 1) {
                iteration = 8;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
        }

        else if (event->key.code == sf::Keyboard::Numpad9 && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            if (iteration < 10 && iteration>0) {
                iteration = (iteration * 10) + 9;
            }
            else if (iteration < 1) {
                iteration = 9;
            }
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
        }

        else if (event->key.code == sf::Keyboard::Enter && m_select >= 0) {
            m_select = -1;
        }

        else if (event->key.code == sf::Keyboard::Backspace && m_select >= 0) {
            int iteration = m_blockInstructions.at(m_select)->getIteration();
            iteration = 0;
            m_blockInstructions.at(m_select)->setIteration(iteration);
            m_blockInstructions.at(m_select)->getTextIteration().setString(std::to_string(iteration));
            std::cout << "Number delete" << std::endl;
        }
    }
}

void BlockManager::draw(sf::RenderWindow* window)
{
    for (int i = 0; i < 9; i++) {
        window->draw(m_blockList[i]);
    }

    window->draw(m_startBloc);

    for (int i = 0; i < m_blockInstructions.size(); i++) {
        m_blockInstructions.at(i)->getTextIteration().setPosition(m_blockInstructions.at(i)->getPosition().x, m_blockInstructions.at(i)->getPosition().y);
        m_blockInstructions.at(i)->draw(window);
    }
}

vector<ExecBlocs*>& const BlockManager::getBlockInstructions()
{
    return m_blockInstructions;
}

bool& const BlockManager::getStart()
{
    return m_start;
}
