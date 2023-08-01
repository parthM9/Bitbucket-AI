#include "About.h"

#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

States About::runState()
{
	displayAbout();
	return getNextState();
}

void About::displayAbout()
{
	cout << "Zorkish::About" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Written by : Parth Madhani(101901858)" << endl;
	cout << "Press ESC or Enter to return to the Main Menu" << endl;
}

States About::getNextState()
{
	//Wait until RETURN is released
	while (GetAsyncKeyState(VK_RETURN)) {}

	//Wait until ESC or RETURN is pressed
	while (!GetAsyncKeyState(VK_ESCAPE) && !GetAsyncKeyState(VK_RETURN)){}

	return StateMainMenu;

}
