#include "CommandProcessor.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;




CommandProcessor::CommandProcessor(GameWorld &aGameWorld, Player &aPlayer)
{
	//Required Entities
	fGameWorld = &aGameWorld;
	fPlayer = &aPlayer;
}


CommandProcessor::~CommandProcessor()
{
}

bool CommandProcessor::executeCommand(string aCommand)
{
	if (aCommand.compare("") == 0)
		return true;
	vector<string> lCommand = vector<string>();

	char* str = &aCommand[0];
	const char *delim = " ";
	char *token;
	char *next_token;
	token = strtok_s(str, delim, &next_token);
	while (token) {
		lCommand.push_back(token);
		token = strtok_s(NULL, delim, &next_token);
	}


	//Go Command
	for each (string s in fGoCommands)
	{
		if (s.compare(lCommand[0]) == 0) {
			string lDirection;
			for (unsigned int i = 1; i < lCommand.size(); i++)
				lDirection += lCommand[i] + " ";

			fGoCommand = GoCommand(fGameWorld, fPlayer, lDirection);
			fGoCommand.execute();
			return true;
		}
	}
	
	//Look Command
	for each (string s in fLookCommands)
	{
		if (s.compare(lCommand[0]) == 0) {
			fLookCommand = LookCommand(fGameWorld, fPlayer,&lCommand);
			fLookCommand.execute();
			return true;
		}
	}


	//Inventory Command
	for each (string s in fInventoryCommands)
	{
		if (s.compare(lCommand[0]) == 0) {
			fInventoryCommand = InventoryCommand(fPlayer);
			fInventoryCommand.execute();
			return true;
		}
	}

	//Attack Command
	for each (string s in fAttackCommands)
	{
		if (s.compare(lCommand[0]) == 0) {
			fAttackCommand.execute();
			return true;
		}
	}

	//Close Command
	for each (string s in fCloseCommands)
	{
		if (s.compare(lCommand[0]) == 0) {
			fCloseCommand.execute();
			return true;
		}
	}

	//Open Command
	for each (string s in fOpenCommands)
	{
		if (s.compare(lCommand[0]) == 0) {
			fOpenCommand.execute();
			return true;
		}
	}

	//Drop Command
	for each (string s in fDropCommands)
	{
		if (s.compare(lCommand[0]) == 0) {
			fDropCommand = DropCommand(fPlayer, fGameWorld, &lCommand);
			fDropCommand.execute();
			return true;
		}
	}

	//Take Command
	for each (string s in fTakeCommands)
	{
		if (s.compare(lCommand[0]) == 0) {
			fTakeCommand = TakeCommand(fPlayer, fGameWorld, &lCommand);
			fTakeCommand.execute();
			return true;
		}
	}

	//Put Command
	for each (string s in fPutCommands)
	{
		if (s.compare(lCommand[0]) == 0) {
			fPutCommand = PutCommand(fPlayer, fGameWorld, &lCommand);
			fPutCommand.execute();
			return true;
		}
	}

	return false;
}
