#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"
#include "BlocBackward.h"
#include "BlocCatch.h"
#include "BlocForward.h"
#include "BlocJump.h"
#include "BlocJumpForward.h"
#include "BlocThrow.h"
#include "BlocWait.h"

class BlockManager {
private:
	//m_blockList[0] = BlocBackward, [1] = BlocCatch, [2] = BlocForward, [3] = BlocJump, [4] = BlocJumpForward, [5] = BlocThrow, [6] = BlocWait
	sf::RectangleShape m_blockList[9];
	//texture of each bloc in the same order of blocklist
	sf::Texture m_blocTexture[9];
	sf::RectangleShape m_startBloc;
	sf::Texture m_startTexture;
	vector<ExecBlocs*> m_blocInstructions;
	int m_select;
	bool m_start;

public:
	BlockManager(sfp::World* world);
	void update(sf::Event* event);
	void draw(sf::RenderWindow* window);
	vector<ExecBlocs*>& const getBlockInstructions();
	bool& const getStart();
	void setStart(bool start);
	void clearBlocInstructions();
};