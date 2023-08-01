#pragma once
#include "State.h"
class SelectAdventure :
	public State
{
public:
	virtual States runState();

	void displaySelectAdventure();
	States getNextState();
};

