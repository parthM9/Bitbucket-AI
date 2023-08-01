#include <iostream>
#include <thread>
#include <conio.h>
#include <chrono> 

#include "MoveHandler.h"
#include "WorldProcessor.h"
#include "Resources.h"

using namespace std;
using namespace std::chrono;

void WaitForInput(bool &aInputRequired, Move &aNextMove, WorldProcessor &aWorld)
{
	while (true)
	{
		if (aInputRequired)
		{
			aNextMove = aWorld.GetMove();
			aInputRequired = false;
		}

	}
}

int main()
{
	bool InputRequired = true;

	WorldProcessor world;
	MoveHandler lMoveHandler;
	Move lNextMove;
	GameState lGameState = Valid;
	//start timer 
	auto start = high_resolution_clock::now();

	thread lInputThread(WaitForInput, ref(InputRequired), ref(lNextMove), ref(world));

	world.DisplayStart();
	world.DisplayMoves(lMoveHandler.GetValidMoves());

	while (true)
	{

		if (!InputRequired) {


			if (!lMoveHandler.ValidateMove(lNextMove))
			{
				world.DisplayMoves(lMoveHandler.GetValidMoves());
				InputRequired = true;
			}

			if (lNextMove == Quit)
				break;

			if (!InputRequired) {
				lMoveHandler.UpdatePosition(lNextMove);
				world.DisplayMoves(lMoveHandler.GetValidMoves());
				InputRequired = true;
			}

			lGameState = lMoveHandler.GetGameState();

			if (lGameState == Win)
			{
				world.DisplayWin();
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - start);

				cout << "Time taken : "
					<< duration.count() << " seconds" << endl;
				break;
			}
			else if (lGameState == Loss)
			{
				world.DisplayLoss();
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - start);

				cout << "Time taken: "
					<< duration.count() << "seconds" << endl;
				break;
			}

		}

	}

	lInputThread.join();

	return 0;
}