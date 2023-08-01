#pragma once
#include "State.h"
class NewHighScore :
	public State
{
public:
	States runState();
	States getNextState();

	void displayNewHighScore();
	void getName();
};

