#pragma once

#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"


class BlocForward : public ExecBlocs {
public:
	void action(Character* player) override;
	BlocForward();
};