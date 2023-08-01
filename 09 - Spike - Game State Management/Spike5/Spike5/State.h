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

	StateGameplay


};

class State
{

public:
	virtual States runState() = 0;
};

