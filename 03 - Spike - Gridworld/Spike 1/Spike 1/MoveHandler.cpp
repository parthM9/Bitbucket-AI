#include "MoveHandler.h"

MoveHandler::MoveHandler()
{
	fPlayerPosition.fXPos = 2;
	fPlayerPosition.fYPos = 7;

}

bool MoveHandler::ValidateMove(Move aMove)
{
	int counter = 0;

	for(Move m : GetValidMoves())
	{
		if (m == aMove)
			counter++;
	}

	if (counter != 0)
		return true;
	else return false;
}

list<Move> MoveHandler::GetValidMoves()
{
	list<Move> result;

	//North
	if (fMap[fPlayerPosition.fYPos - 1][fPlayerPosition.fXPos] != '#')
		result.push_front(North);
	//South
	if (fMap[fPlayerPosition.fYPos + 1][fPlayerPosition.fXPos] != '#')
		result.push_front(South);
	//East
	if (fMap[fPlayerPosition.fYPos][fPlayerPosition.fXPos + 1] != '#')
		result.push_front(East);
	//West
	if (fMap[fPlayerPosition.fYPos][fPlayerPosition.fXPos - 1] != '#')
		result.push_front(West);

	return result;
}

void MoveHandler::UpdatePosition(Move aMove)
{
	switch (aMove)
	{
	case North:
		fPlayerPosition.fYPos--;
		break;
	case South:
		fPlayerPosition.fYPos++;
		break;
	case East:
		fPlayerPosition.fXPos++;
		break;
	case West:
		fPlayerPosition.fXPos--;
		break;
	default:
		break;
	}
}

GameState MoveHandler::GetGameState()
{
	if (fMap[fPlayerPosition.fYPos][fPlayerPosition.fXPos] == 'D')
		return Loss;
	else if (fMap[fPlayerPosition.fYPos][fPlayerPosition.fXPos] == 'G')
		return Win;
	else return Valid;
}