#include "State.h"

#pragma once

class MainMenu : public State
{
public:
	virtual States runState();

	void displayMenu();
	States getNextState();

private:

};
