#pragma once
#include "State.h"
#include "Player.h"
#include "GameWorld.h"
#include "WorldProcessor.h"
#include "CommandProcessor.h"

class GameplayVoidWorld :
	public State
{
public:
	GameplayVoidWorld();
	~GameplayVoidWorld();

	virtual States runState();

	States getNextState();
	void initialiseWorld();

private:
	Player fPlayer;
	GameWorld fGameWorld;
	bool fFirstRun;
	CommandProcessor* fCommandProcessor;
};

