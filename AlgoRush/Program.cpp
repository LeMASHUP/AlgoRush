#include "Program.h"
#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

Program::Program(vector<int> blocksList) : m_lastBlockTime(m_clock.getElapsedTime()), m_pc(0), m_blocksList(blocksList)
{
	
}

void Program::play(Character* character)
{
	m_play = true;
	//m_blocksList[m_pc].action(character);
	m_lastBlockTime = m_clock.getElapsedTime();
	m_pc++;
}

void Program::update(Character* character)
{
	if ((m_clock.getElapsedTime() - m_lastBlockTime).asMilliseconds() > 4000) {
		//m_blocksList[m_pc].action(character);
		m_lastBlockTime = m_clock.getElapsedTime();
		m_pc++;
	}
}
