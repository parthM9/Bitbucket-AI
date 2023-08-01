#include "LookCommand.h"
#include <iostream>

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
	if (fCommands->size() > 1)
	{
		if (fCommands->at(1).compare("at") == 0)
		{
			cout << "Look at Command" << endl;
			return;
		}
		else if (fCommands->at(1).compare("in") == 0)
		{
			cout << "Look in Command" << endl;
			return;
		}
	}
	fGameWorld->ShowVisibleItems(fPlayer->getLocation());

}
