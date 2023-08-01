#include "WorldProcessor.h"


Move WorldProcessor::GetMove()
{
	char lInput;

	cin >> lInput;
	lInput = toupper(lInput);

	switch (lInput)
	{
	default:
		return GetMove();
		break;
	case 'N':
		return North;
		break;
	case 'S':
		return South;
		break;
	case 'E':
		return East;
		break;
	case 'W':
		return West;
		break;
	case 'Q':
		return Quit;
		break;
	}
}

void WorldProcessor::DisplayMoves(list<Move> aMoves)
{
	cout << "You can move ";

	for(Move m : aMoves)
	{
		switch (m)
		{
		case North:
			cout << "North";
			break;
		case South:
			cout << "South";
			break;
		case East:
			cout << "East";
			break;
		case West:
			cout << "West";
			break;
		default:
			break;
		}

		cout << ", ";
	}

	cout << ":> ";

}

void WorldProcessor::DisplayStart()
{
	cout << "Welcome to GridWorld : Quantised Excitement.Fate is waiting for You!" << endl;
	cout << "Valid commands : N, S, E and W for direction. Q to quit the game." << endl;
}

void WorldProcessor::DisplayWin()
{
	cout << "Wow - you hasve discovered a large chest filled with GOLD coins!" << endl;
	cout << "YOU WIN!" << endl;
	cout << "Thanks for playing.There probably will never be a next time." << endl;
}

void WorldProcessor::DisplayLoss()
{
	cout << "Unlucky... you have fallen down a pit." << endl;
	cout << "YOU HAVE DIED!" << endl;
	cout << "Thanks for playing. Maybe next time." << endl;
}