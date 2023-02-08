#include "Program.h"
#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

Program::Program(/*vector<ExecBlocs*> blocksList*/) : m_lastBlockTime(m_clock.getElapsedTime()), m_pc(0), /*m_blocksList(blocksList),*/ m_init(false)
{
	
}

void Program::init(Character* character)
{
	//m_blocksList[m_pc].action(character);
	m_lastBlockTime = m_clock.getElapsedTime();
	m_pc++;
	m_init = true;
}

void Program::update(Character* character)
{
	if ((m_clock.getElapsedTime() - m_lastBlockTime).asMilliseconds() > 4000) {
		//m_blocksList[m_pc].action(character);
		m_lastBlockTime = m_clock.getElapsedTime();
		m_pc++;
	}
}
