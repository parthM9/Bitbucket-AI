#include "Help.h"


#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;


States Help::runState()
{
	displayHelp();
	return getNextState();
}

void Help::displayHelp()
{
	cout << "Zorkish::Help" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "The following commands are supported :" << endl;
	cout << "[go] _" << endl;
	cout << "look at _" << endl;
	cout << "look in _" << endl;
	cout << "inventory" << endl;
	cout << "open _[with _]" << endl;
	cout << "close _" << endl;
	cout << "attack _ with _" << endl;
	cout << "take _[from _]" << endl;
	cout << "put _ in _" << endl;
	cout << "drop _" << endl;
	cout << "quit" << endl;
	cout << "[up arrow] to repeat last command" << endl;
	cout << "hiscore(for testing)" << endl;
	cout << "Press ESC or Enter to return to the Main Menu" << endl;
}

States Help::getNextState()
{
	//Wait until RETURN is released
	while (GetAsyncKeyState(VK_RETURN)) {}

	//Wait until ESC or RETURN is pressed
	while (!GetAsyncKeyState(VK_ESCAPE) && !GetAsyncKeyState(VK_RETURN)) {}

	return StateMainMenu;

}

