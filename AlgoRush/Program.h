#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

class Program
{

private:

	sf::Clock m_clock;
	sf::Time m_lastBlockTime;
	int m_pc;
	int m_sizeList;
	//ExecBlocks m_blocksList[];


public:

	Program();

	void execution();

};