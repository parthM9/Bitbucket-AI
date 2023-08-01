#include "PutCommand.h"
#include <iostream>
#include <algorithm>

using namespace std;

PutCommand::PutCommand(Player* aPlayer, GameWorld* aGameWorld, vector<string>* aCommands)
{
	fPlayer = aPlayer;
	fGameWorld = aGameWorld;
	fCommands = aCommands;
}

PutCommand::PutCommand()
{
}


PutCommand::~PutCommand()
{
}

void PutCommand::execute() {

	//put _ in _

	Location* lLocation = fGameWorld->getLocation(fPlayer->getLocation());

	for each (CompositeGameEntity* e in lLocation->getEntities())
	{
		string lEntityName = e->getName();
		transform(lEntityName.begin(), lEntityName.end(), lEntityName.begin(), tolower);

		if (lEntityName.compare(fCommands->at(3)) == 0)
		{
			for each (Entity* item in fPlayer->GetInventory())
			{
				string lItemName = item->getName();
				transform(lItemName.begin(), lItemName.end(), lItemName.begin(), tolower);

				if (lItemName.compare(fCommands->at(1)) == 0)
				{
					if (e->add(item)) {
						fPlayer->RemoveItemFromInventory(item);
						cout << "You put your " << lItemName << " in the " << lEntityName << "." << endl;
						return;
					}
					else
					{
						cout << "You cant put that in there!" << endl;
						return;
					}
				}

			}
			cout << "You do not have a " << fCommands->at(1) << "!" << endl;
			return;
		}
		
	}
	cout << "You cannot find a " << fCommands->at(3) << "!" << endl;
	return;
}
