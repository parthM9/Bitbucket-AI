#pragma once
#include "State.h"
class HallOfFame :
	public State
{
public:
	virtual States runState();

	void displayHallOfFame();
	States getNextState();
};

