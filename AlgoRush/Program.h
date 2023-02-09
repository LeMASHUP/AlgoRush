#pragma once
#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include "ExecBlocs.h"

class Program
{

private:

	sf::Clock m_clock;
	sf::Time m_lastBlockTime;
	bool m_init;
	int m_pc;
	int m_ic;
	vector<ExecBlocs*> m_blocksList;

public:

	Program(vector<ExecBlocs*> blocksList);

	void init(Character* character);

	void update(Character* character);

};