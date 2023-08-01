#pragma once


enum States
{
	StateMainMenu,
	StateSelectAdventure,
	StateHallOfFame,
	StateHelp,
	StateAbout,
	StateQuit,
	StateNewHighScore,

	StateGameplayVoidWorld


};

class State
{

public:
	virtual States runState() = 0;
};

