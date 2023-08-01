#include "TakeCommand.h"
#include <iostream>
#include <algorithm>

using namespace std;
static int i = 0;
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
				if (fGameWorld->EntityHasComponent(e, Takeable) || i==1)
				{
					cout << "You take the " << fCommands->at(1) << endl;
					fPlayer->AddItemToInventory(e);
					lLocation->remove(e);


					//Test Message Handler
					lLocation->CreateMessage(lLocation->getName(), "You have a message");
					lLocation->SendMessage();
				}
				else
				{
					cout << "Chest is now takeable" << endl;
					i = 1;
				}
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
					if (fGameWorld->EntityHasComponent(item, Takeable) || i==1)
					{
						cout << "You take the " << lItemName << " from the " << lEntityName << "." << endl;
						fPlayer->AddItemToInventory(item);
						e->remove(item);

						//Test Message Handler
						cout << "Set not receiving messages..." << endl;
						item->ToggleReceiveMessages();
						cout << "Send message..." << endl;
						lLocation->CreateMessage(item->getName(), "You have a message");
						lLocation->SendMessage();
						cout << "Check Messages on Blackboard..." << endl;
						item->CheckBlackboard();
						cout << "Done!" << endl;
					}
					else {
						cout << "This is not takeable" << endl;
						
					}
					return;
				}

			}
			cout << "There is no " << fCommands->at(1) << " in the " << lEntityName << "." << endl;
			return;
		}
	}
}
