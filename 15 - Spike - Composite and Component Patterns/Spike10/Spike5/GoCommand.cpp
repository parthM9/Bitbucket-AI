#include "GoCommand.h"
#include <iostream>

using namespace std;


GoCommand::GoCommand(GameWorld* aGameWorld, Player* aPlayer, string aDirection)
{
	fGameWorld = aGameWorld;
	fPlayer = aPlayer;
	fDirection = aDirection;
}


GoCommand::~GoCommand()
{
}

void GoCommand::execute()
{
	fPlayer->setLocation(fGameWorld->ValidateMove(fPlayer->getLocation(), fDirection));
	fGameWorld->ShowLocation(fPlayer->getLocation());
}
