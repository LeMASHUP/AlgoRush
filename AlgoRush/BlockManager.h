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
	//m_blockList[0] correspond à BlocBackward, [1] = BlocCatch, [2] = BlocForward, [3] = BlocJump, [4] = BlocJumpForward, [5] = BlocThrow, [6] = BlocWait
	sf::RectangleShape m_blockList[8];
	//m_blocTexture[0] correspond au textures de BlocBackward, [1] = BlocCatch, [2] = BlocForward, [3] = BlocJump, [4] = BlocJumpForward, [5] = BlocThrow, [6] = BlocWait
	sf::Texture m_blocTexture[8];
	vector<ExecBlocs*> m_blockInstructions;
	int m_select;
public:
	BlockManager(sfp::World* world);
	void update(sf::Event* event);
	void draw(sf::RenderWindow* window);
};