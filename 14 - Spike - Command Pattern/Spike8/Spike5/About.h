#pragma once
#include "State.h"
class About : public State
{
public:
	virtual States runState();

	void displayAbout();
	States getNextState();

private:

};

