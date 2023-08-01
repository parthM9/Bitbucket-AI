#pragma once
#include "State.h"
#include "Player.h"
class Gameplay :
	public State
{
public:
	Gameplay();

	virtual States runState();

	States getNextState();
	void initialiseWorld();

private:
	Player fPlayer;
};

