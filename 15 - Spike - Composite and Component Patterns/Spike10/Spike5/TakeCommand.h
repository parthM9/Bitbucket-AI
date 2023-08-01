#pragma once
#include "Command.h"
#include "Player.h"
#include "GameWorld.h"

class TakeCommand :
	public Command
{
public:
	TakeCommand();
	TakeCommand(Player* aPlayer, GameWorld* aGameWorld, vector<string>* aCommands);
	~TakeCommand();

	virtual void execute();

	Player* fPlayer;
	GameWorld* fGameWorld;
	vector<string>* fCommands;
};

