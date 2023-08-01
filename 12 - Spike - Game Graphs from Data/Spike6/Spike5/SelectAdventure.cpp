#include "SelectAdventure.h"
#include <iostream>
#include <stdio.h>

using namespace std;

States SelectAdventure::runState()
{

	displaySelectAdventure();
	return getNextState();
}

void SelectAdventure::displaySelectAdventure()
{
	cout << "Zorkish::Select Adventure" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Choose your adventure :" << endl;
	cout << "1. Mountain World" << endl;
	cout << "2. Water World" << endl;
	cout << "3. Box World" << endl;
	cout << "Select 1 - 3 : > ";
}

States SelectAdventure::getNextState()
{
	char input;
	cin >> input;

	switch (input)
	{
	case '1':
		return StateGameplay;
		break;
	case '2':
		return StateMainMenu;
		break;
	case '3':
		return StateMainMenu;
		break;
	default:
		return StateSelectAdventure;
		break;
	}

}