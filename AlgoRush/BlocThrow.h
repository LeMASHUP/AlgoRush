#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"


class BlocThrow : public ExecBlocs {
public:
	void action() override;
	BlocThrow();
};