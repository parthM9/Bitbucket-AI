#pragma once
#include "Command.h"
#include "Player.h"
#include "GameWorld.h"

class GoCommand :
	public Command
{
public:
	GoCommand() {}
	GoCommand(GameWorld* aGameWorld, Player* aPlayer, string lDirection);
	~GoCommand();

	virtual void execute();

private:
	GameWorld* fGameWorld;
	Player*  fPlayer;
	string fDirection;
};

