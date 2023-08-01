#include "DropCommand.h"
#include <iostream>
#include <algorithm>

using namespace std;

DropCommand::DropCommand(Player* aPlayer, GameWorld* aGameWorld, vector<string>* aCommands)
{
	fPlayer = aPlayer;
	fGameWorld = aGameWorld;
	fCommands = aCommands;
}

DropCommand::DropCommand()
{
}


DropCommand::~DropCommand()
{
}

void DropCommand::execute() {
	Location* lLocation = fGameWorld->getLocation(fPlayer->getLocation());

	for each (Entity* e in fPlayer->GetInventory())
	{
		string lEntityName = e->getName();
		transform(lEntityName.begin(), lEntityName.end(), lEntityName.begin(), tolower);

		if (lEntityName.compare(fCommands->at(1)) == 0)
		{
			cout << "You drop the " << fCommands->at(1) << " on the ground." << endl;
			fPlayer->RemoveItemFromInventory(e);
			lLocation->add(e);
		}
	}
}