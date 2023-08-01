#include "TakeCommand.h"
#include <iostream>
#include <algorithm>

using namespace std;

TakeCommand::TakeCommand()
{}

TakeCommand::TakeCommand(Player* aPlayer, GameWorld* aGameWorld, vector<string>* aCommands)
{
	fPlayer = aPlayer;
	fGameWorld = aGameWorld;
	fCommands = aCommands;
}


TakeCommand::~TakeCommand()
{
}

void TakeCommand::execute() {

	Location* lLocation = fGameWorld->getLocation(fPlayer->getLocation());

	//take _
	if (fCommands->size() == 2) {
		for each (Entity* e in lLocation->getEntities())
		{
			string lEntityName = e->getName();
			transform(lEntityName.begin(), lEntityName.end(), lEntityName.begin(), tolower);

			if (lEntityName.compare(fCommands->at(1)) == 0)
			{
				if (fGameWorld->EntityHasComponent(e, Takeable))
				{
					cout << "You take the " << fCommands->at(1) << endl;
					fPlayer->AddItemToInventory(e);
					lLocation->remove(e);
				}
				else cout << "You cannot take that!" << endl;
				return;
			}

		}
		cout << "You cannot find the " << fCommands->at(1) << "." << endl;
		return;
	}

	//take _ from _
	for each (CompositeGameEntity* e in lLocation->getEntities())
	{
		string lEntityName = e->getName();
		transform(lEntityName.begin(), lEntityName.end(), lEntityName.begin(), tolower);

		if (lEntityName.compare(fCommands->at(3)) == 0)
		{
			for each (Entity* item in e->getEntities())
			{
				string lItemName = item->getName();
				transform(lItemName.begin(), lItemName.end(), lItemName.begin(), tolower);

				if (lItemName.compare(fCommands->at(1)) == 0)
				{
					if (fGameWorld->EntityHasComponent(item, Takeable))
					{
						cout << "You take the " << lItemName << " from the " << lEntityName << "." << endl;
						fPlayer->AddItemToInventory(item);
						e->remove(item);
					}
					else cout << "You cannot take that!" << endl;
					return;
				}

			}
			cout << "There is no " << fCommands->at(1) << " in the " << lEntityName << "." << endl;
			return;
		}
	}
}
