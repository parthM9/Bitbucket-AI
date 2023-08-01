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
	void AddItemToLocation(string aLocationName, string aItemName);
	void PrintWorld();
	void ShowValidMoves(int aPlayerLocation);
	void ShowLocation(int aPlayerLocation);
	void ShowVisibleItems(int aPlayerLocation);
	int ValidateMove(int aPlayerLocation, string aMove);

private:
	Graph fWorldMap;
	vector<string> fLocations;
	vector<list<string>> fLocationItems;
	
};

