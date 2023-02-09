#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "Execblocs.h"


class BlocCatch : public ExecBlocs {
private:
	//Object* m_object;
public:
	void action(Character* player) override;
	BlocCatch(/*Object* m_object*/);
};