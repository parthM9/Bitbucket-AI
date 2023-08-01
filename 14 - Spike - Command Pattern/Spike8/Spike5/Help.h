#pragma once
#include "State.h"
class Help : public State
{
public:

	virtual States runState();

	void displayHelp();
	States getNextState();
};

