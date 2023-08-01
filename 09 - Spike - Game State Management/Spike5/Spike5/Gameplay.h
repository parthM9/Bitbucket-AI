#pragma once
#include "State.h"
class Gameplay :
	public State
{
public:
	virtual States runState();

	States getNextState();
	void initialiseWorld();
};

