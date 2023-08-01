#include "NewHighScore.h"

#include <iostream>

using namespace std;

States NewHighScore::runState()
{
	displayNewHighScore();
	getName();
	return getNextState();
}

States NewHighScore::getNextState()
{

	return StateHallOfFame;
}

void NewHighScore::displayNewHighScore()
{
	cout << "Zorkish::New High Score" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Congratulations!" << endl;
	cout << "You have made it to the Zorkish Hall Of Fame" << endl;
	cout << "Adventure : [the adventure world played]" << endl;
	cout << "Score : [the players score]" << endl;
	cout << "Moves : [number of moves player made]" << endl;
	cout << "Please type your name and press enter:> ";
}

void NewHighScore::getName()
{
	char input;
	cin >> input;
}