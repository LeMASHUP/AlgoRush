#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"


class BlocThrow : public ExecBlocs {
private:
	//Object* m_object;
public:
	void action(Character* player) override;
	BlocThrow(/*Object* m_object*/);
};