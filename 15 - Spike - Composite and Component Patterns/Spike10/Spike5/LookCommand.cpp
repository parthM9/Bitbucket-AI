#include "LookCommand.h"
#include <iostream>
#include <algorithm>

using namespace std;


LookCommand::LookCommand(GameWorld* aGameWorld, Player* aPlayer, vector<string>* aCommands)
{
	fGameWorld = aGameWorld;
	fPlayer = aPlayer;
	fCommands = aCommands;
}


LookCommand::~LookCommand()
{
}

void LookCommand::execute()
{
	string s = "";



	if (fCommands->size() > 1)
	{
		if (fCommands->size() < 3)
		{
			cout << "Command incomplete!" << endl;
			return;
		}

		//Look at _
		if (fCommands->at(1).compare("at") == 0)
		{
			Location* lLocation = fGameWorld->getLocation(fPlayer->getLocation());

			if (fCommands->size() == 3) {
				for each (CompositeGameEntity* e in lLocation->getEntities())
				{
					string lEntityName = e->getName();
					transform(lEntityName.begin(), lEntityName.end(), lEntityName.begin(), tolower);

					if (lEntityName.compare(fCommands->at(2)) == 0)
					{
						e->display();
						return;
					}
				}
				cout << "You cannot see a " << fCommands->at(2) << "." << endl;
				return;
			}
		

			//Look at _ in inventory
			if (fCommands->at(3).compare("in") == 0)
			{
				if (fCommands->at(4).compare("inventory") == 0)
				{
					for each (Entity* e in fPlayer->GetInventory())
					{
						string lEntityName = e->getName();
						transform(lEntityName.begin(), lEntityName.end(), lEntityName.begin(), tolower);

						if (lEntityName.compare(fCommands->at(2)) == 0)
						{
							e->display();
							return;
						}
					}
					cout << "You don't have a " << fCommands->at(2) << endl;
					return;
				}

				//For each composite entity in the location
				for each (CompositeGameEntity* lLocationEntities in lLocation->getEntities())
				{
					string lEntityName = lLocationEntities->getName();
					transform(lEntityName.begin(), lEntityName.end(), lEntityName.begin(), tolower);

					//Test if it is this one
					if (lEntityName.compare(fCommands->at(4)) == 0)
					{
						//If it is, for each entity in the composite entity
						for each (Entity* lEntityEntities in lLocationEntities->getEntities())
						{
							string lEntityName = lEntityEntities->getName();
							transform(lEntityName.begin(), lEntityName.end(), lEntityName.begin(), tolower);
							
							if (lEntityName.compare(fCommands->at(2)) == 0)
								lEntityEntities->display();

						}
						return;
					}
				}
			}
		}

		//Look in _
		else if (fCommands->at(1).compare("in") == 0)
		{
			Location* lLocation = fGameWorld->getLocation(fPlayer->getLocation());
			for each (CompositeGameEntity* e in lLocation->getEntities())
			{
				string lEntityName = e->getName();
				transform(lEntityName.begin(), lEntityName.end(), lEntityName.begin(), tolower);

				if (lEntityName.compare(fCommands->at(2)) == 0)
				{
					cout << "You look in the " << fCommands->at(2) << ". You see:" << endl;
					e->displayAll();
				}
			}
			return;
		}
	}
	fGameWorld->ShowVisibleItems(fPlayer->getLocation());

}
