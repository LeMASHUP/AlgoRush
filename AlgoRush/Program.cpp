#include "Program.h"
#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

Program::Program(vector<ExecBlocs*> blocksList) : m_lastBlockTime(m_clock.getElapsedTime()), m_pc(0), m_ic(0), m_blocksList(blocksList), m_init(false)
{
	
}

void Program::init(Character* character)
{
	m_lastBlockTime = m_clock.getElapsedTime() - sf::seconds(1.4f);
	m_init = true;
}

void Program::update(Character* character, Level1* level1, Level2* level2, int& state)
{
	std::cout << m_ic << std::endl;
	std::cout << m_pc << std::endl;
	if ((m_clock.getElapsedTime() - m_lastBlockTime).asMilliseconds() <= 1500 && (m_clock.getElapsedTime() - m_lastBlockTime).asMilliseconds() > 1200 && character->getVelocity().y < 0.1) {
		character->setVelocity(Vector2f(0, character->getVelocity().y));
	}
	else if ((m_clock.getElapsedTime() - m_lastBlockTime).asMilliseconds() > 1500 && character->getVelocity().y < 0.1) {
		if (m_pc < m_blocksList.size()) {
			m_blocksList.at(m_pc)->action(character);
			m_lastBlockTime = m_clock.getElapsedTime();
			if (m_ic + 1 == m_blocksList.at(m_pc)->getIteration())
			{
				m_pc++;
				m_ic = 0;
			}
			else {
				m_ic++;
			}
		}
	}
	if (m_pc == m_blocksList.size() && (m_clock.getElapsedTime() - m_lastBlockTime).asMilliseconds() > 1500) {
		if (state == 1) level1->setLevelsElapsedTime();
		else if (state == 2) level2->setLevelsElapsedTime();
		state = 5;
	}
}
