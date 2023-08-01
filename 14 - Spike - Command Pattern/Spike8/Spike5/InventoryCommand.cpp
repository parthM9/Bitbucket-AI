#include "InventoryCommand.h"


InventoryCommand::InventoryCommand(Player* aPlayer)
{
	fPlayer = aPlayer;
}

InventoryCommand::InventoryCommand()
{
}


InventoryCommand::~InventoryCommand()
{
}

void InventoryCommand::execute()
{
	fPlayer->CheckInventory();
}
