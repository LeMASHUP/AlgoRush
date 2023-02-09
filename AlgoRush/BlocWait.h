#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"
#include "Character.h"


class BlocWait : public ExecBlocs {
public:
	void action(Character* player) override;
	BlocWait();
};