#pragma once
#include "Resources.h"
#include <list>
#include <iostream>
#include <ctype.h>

class WorldProcessor
{
public:
	Move GetMove();

	void DisplayMoves(list<Move> aMoves);

	void DisplayStart();
	void DisplayWin();
	void DisplayLoss();
};