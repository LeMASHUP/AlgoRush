#include "Character.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

class Program
{

private:

	sf::Clock m_clock;
	sf::Time m_lastBlockTime;
	bool m_play;
	int m_pc;
	int m_sizeList;
	vector<int> m_blocksList;
	//vector<Execblocs> m_blocksList;

public:

	Program(vector<int> blocksList);

	void play(Character* character);

	void update(Character* character);

};