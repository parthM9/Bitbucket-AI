#pragma once
#include "Player.h"
#include "GameWorld.h"

class PutCommand
{
public:
	PutCommand::PutCommand(Player* aPlayer, GameWorld* aGameWorld, vector<string>* aCommands);
	PutCommand();
	~PutCommand();

	virtual void execute();

private:
	Player* fPlayer;
	GameWorld* fGameWorld;
	vector<string>* fCommands;
};

