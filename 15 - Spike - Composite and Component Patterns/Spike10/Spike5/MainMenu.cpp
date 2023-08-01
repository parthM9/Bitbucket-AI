#include "MainMenu.h"
#include <iostream>
#include <stdio.h>

using namespace std;

States MainMenu::runState()
{

	displayMenu();
	return getNextState();
}

void MainMenu::displayMenu()
{
	cout << "Zorkish::Main Menu" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Welcome to Zorkish Adventures" << endl;
	cout << "1. Select Adventure and Play" << endl;
	cout << "2. Hall Of Fame" << endl;
	cout << "3. Help" << endl;
	cout << "4. About" << endl;
	cout << "5. Quit" << endl;
	cout << "Select 1 - 5:> ";
}

States MainMenu::getNextState()
{
	char input;
	cin >> input;

	switch (input)
	{
	case '1':
		return StateSelectAdventure;
		break;
	case '2':
		return StateHallOfFame;
		break;
	case '3':
		return StateHelp;
		break;
	case '4':
		return StateAbout;
		break;
	case '5':
		return StateQuit;
		break;
	default:
		return StateMainMenu;
		break;
	}

}