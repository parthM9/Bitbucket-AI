#include "GameplayVoidWorld.h"
#include "Player.h"

#include <String>
#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

GameplayVoidWorld::GameplayVoidWorld()
{
	WorldProcessor w;
	fPlayer = Player();
	fGameWorld = w.loadWorld("TestWorld2.txt");
	fFirstRun = true;
	fCommandProcessor = new CommandProcessor(fGameWorld, fPlayer);
}

GameplayVoidWorld::~GameplayVoidWorld()
{
	delete fCommandProcessor;
}

States GameplayVoidWorld::runState()
{
	if (fFirstRun)
	{
		initialiseWorld();
		fGameWorld.ShowLocation(fPlayer.getLocation());
		fFirstRun = false;
		cin.ignore();
		}



	return getNextState();
}

States GameplayVoidWorld::getNextState()
{
	string input;

	cout << ":>";

	getline(cin, input);


	//String to lowercase
	transform(input.begin(), input.end(), input.begin(), tolower);

	if (!fCommandProcessor->executeCommand(input))
	{
		cout << "You don't know how to do that!" << endl;
	}

	if (input == "quit")
	{
		//Wait until RETURN is released
		while (GetAsyncKeyState(VK_RETURN)) {}

		cout << "Your adventure has ended without fame or fortune." << endl;
		cout << "Press ENTER to continue...";

		//Wait until ESC or RETURN is pressed
		while (!GetAsyncKeyState(VK_RETURN)) {}
		return StateMainMenu;
	}
	else if (input == "hiscore")
	{
		//Wait until RETURN is released
		while (GetAsyncKeyState(VK_RETURN)) {}

		cout << "You have entered the magic word and will now see the 'New High Score' screen." << endl;
		cout << "Press ENTER to continue...";

		//Wait until ESC or RETURN is pressed
		while (!GetAsyncKeyState(VK_RETURN)) {}
		return StateNewHighScore;
	}



	runState();

	return StateGameplayVoidWorld;
	
}

void GameplayVoidWorld::initialiseWorld()
{
	cout << "Welcome to Zorkish: Void World" << endl;
	cout << "This world is simple and pointless.Used it to test Zorkish phase 1 spec." << endl;
}
