#pragma once

#include "SFML/Graphics.hpp"
#include "Execblocs.h"


class BlocCatch : public ExecBlocs {
private:
	//Object* m_object;
public:
	void action(Character* player) override;
	BlocCatch(/*Object* m_object*/);
};