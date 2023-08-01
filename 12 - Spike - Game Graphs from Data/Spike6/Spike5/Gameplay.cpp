#include "Gameplay.h"
#include "Player.h"

#include <String>
#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

Gameplay::Gameplay()
{
	WorldProcessor w;
	fPlayer = Player();
	fGameWorld = w.loadWorld("./TestWorld2.txt");
	fFirstRun = true;
}

States Gameplay::runState()
{
	if (fFirstRun)
	{
		initialiseWorld();
		fFirstRun = false;
	}

	fGameWorld.ShowLocation(fPlayer.getLocation());
	fGameWorld.PrintWorld();

	return getNextState();
}

States Gameplay::getNextState()
{
	string input;

	cout << ":>";

	cin >> input;
	
	//String to lowercase
	transform(input.begin(), input.end(), input.begin(), tolower);

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

	else if (input.find("go") != string::npos)
	{
		string lDirection;
		cin >> lDirection;
		fPlayer.setLocation(fGameWorld.ValidateMove(fPlayer.getLocation(),lDirection));
		cout << fPlayer.getLocation();
		system("pause");
		runState();
	}

	return StateGameplay;
	
}

void Gameplay::initialiseWorld()
{
	cout << "Welcome to Zorkish: Void World" << endl;
	cout << "This world is simple and pointless.Used it to test Zorkish phase 1 spec." << endl;
}
