#pragma once
#include "Command.h"
#include "Player.h"
#include "GameWorld.h"

class DropCommand :
	public Command
{
public:
	DropCommand(Player* aPlayer, GameWorld* aGameWorld, vector<string>* aCommands);
	DropCommand();
	~DropCommand();

	virtual void execute();

private:
	Player* fPlayer;
	GameWorld* fGameWorld;
	vector<string>* fCommands;
};

