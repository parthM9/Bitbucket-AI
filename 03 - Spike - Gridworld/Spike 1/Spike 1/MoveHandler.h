#pragma once
#include "Resources.h"
#include <list>

class MoveHandler
{
private:
	char fMap[9][8] = {
		{'#','#','#','#','#','#','#','#'},
		{'#','G',' ','D','#','D',' ','#'},
		{'#',' ',' ',' ','#',' ',' ','#'},
		{'#','#','#',' ','#',' ','D','#'},
		{'#',' ',' ',' ','#',' ',' ','#'},
		{'#',' ','#','#','#','#',' ','#'},
		{'#',' ',' ',' ',' ',' ',' ','#'},
		{'#','#','S','#','#','#','#','#'},
		{'#','#','#','#','#','#','#','#'}
	};

	Position fPlayerPosition;

public:
	MoveHandler();

	bool ValidateMove(Move aMove);
	list<Move> GetValidMoves();
	void UpdatePosition(Move aMove);
	GameState GetGameState();
};