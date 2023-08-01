#pragma once

#include "State.h"

class StateManager
{
private:
	State* fCurrentState;
	bool fQuitGame;

public:
	StateManager();

	void SetState(States aState);
	void run();
};