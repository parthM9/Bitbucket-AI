#pragma once

#include "State.h"

class StateManager
{
private:

	friend class UnitTest1;
	State* fCurrentState;
	bool fQuitGame;
	States fCurrentStateName;

public:
	StateManager();

	void SetState(States aState);
	void run();
	States getState();

};