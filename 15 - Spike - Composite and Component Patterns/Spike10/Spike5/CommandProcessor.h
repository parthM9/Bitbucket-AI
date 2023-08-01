#pragma once
#include <string>
#include <list>

#include "GoCommand.h"
#include "LookCommand.h"
#include "InventoryCommand.h"
#include "OpenCommand.h"
#include "CloseCommand.h"
#include "AttackCommand.h"
#include "TakeCommand.h"
#include "PutCommand.h"
#include "DropCommand.h"

#include "Player.h"
#include "GameWorld.h"

using namespace std;

class CommandProcessor
{
public:
	CommandProcessor();
	~CommandProcessor();


	CommandProcessor(GameWorld& aGameWorld, Player& aPlayer);

	bool executeCommand(string aCommand);

private:
	//Required Entities
	GameWorld* fGameWorld;
	Player* fPlayer;

	//Commands
	GoCommand fGoCommand;
	LookCommand fLookCommand;
	InventoryCommand fInventoryCommand;
	AttackCommand fAttackCommand;
	CloseCommand fCloseCommand;
	OpenCommand fOpenCommand;
	DropCommand fDropCommand;
	TakeCommand fTakeCommand;
	PutCommand fPutCommand;

	//Command Lists
	const list<string> fGoCommands = {"go","run"};
	const list<string> fLookCommands = {"look"};
	const list<string> fInventoryCommands = {"inventory"};
	const list<string> fAttackCommands = { "attack", "hit" };
	const list<string> fCloseCommands = { "close", "shut" };
	const list<string> fOpenCommands = { "open" };
	const list<string> fDropCommands = { "drop" };
	const list<string> fTakeCommands = { "take" };
	const list<string> fPutCommands = { "put", "place" };
};

