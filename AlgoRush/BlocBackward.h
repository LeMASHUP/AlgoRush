#pragma once

#include "Execblocs.h"

class BlocBackward : public ExecBlocs {
public:
	void action(Character* player) override;
	BlocBackward();
};