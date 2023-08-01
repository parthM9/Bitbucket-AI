#pragma once
#include "Graph.h"
#include <iostream>
#include <string>

class GameWorld
{
public:
	GameWorld();
	~GameWorld();

	void AddLocation(string aLocationName, list <pair <int, string>> aPaths);
	void PrintWorld();
	void ShowValidMoves(int aPlayerLocation);
	void ShowLocation(int aPlayerLocation);
	int ValidateMove(int aPlayerLocation, string aMove);

private:
	Graph fWorldMap;
	vector<string> fLocations;
	
};

