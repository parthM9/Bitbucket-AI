#pragma once
#include "State.h"
class Quit :
	public State
{
public:
	virtual States runState();
};

