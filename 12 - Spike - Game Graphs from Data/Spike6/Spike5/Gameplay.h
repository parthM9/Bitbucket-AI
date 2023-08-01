#pragma once
#include "State.h"
#include "Player.h"
#include "GameWorld.h"
#include "WorldProcessor.h"

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
	GameWorld fGameWorld;
	bool fFirstRun;
};

