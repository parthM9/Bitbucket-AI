#pragma once
#include "Command.h"
#include "Player.h"
#include "GameWorld.h"

class LookCommand :
	public Command
{
public:
	LookCommand() {}
	LookCommand(GameWorld* aGameWorld, Player* aPlayer, vector<string>* aCommands);
	~LookCommand();

	virtual void execute();

private:
	GameWorld* fGameWorld;
	Player*  fPlayer;
	vector<string>* fCommands;
};

