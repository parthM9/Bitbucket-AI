#pragma once
#include "Command.h"
#include "Player.h"

class InventoryCommand :
	public Command
{
public:
	InventoryCommand(Player* aPlayer);
	InventoryCommand();
	~InventoryCommand();

	virtual void execute();

private:
	Player* fPlayer;
};

