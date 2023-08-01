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
	cout << "quit" << endl;
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

