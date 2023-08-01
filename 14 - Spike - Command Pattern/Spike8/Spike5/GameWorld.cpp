#include "GameWorld.h"
#include <algorithm>



GameWorld::GameWorld()
{
	fWorldMap = Graph();
	fLocations = vector<string>();
	fLocationItems = vector<list<string>>(25);
}


GameWorld::~GameWorld()
{
}

void GameWorld::PrintWorld()
{
	fWorldMap.printGraph();
}

void GameWorld::ShowValidMoves(int aPlayerLocation)
{
	for each (pair<int,string> p in fWorldMap.getConnections(aPlayerLocation))
	{
		cout << p.second << endl;
	}
}

void GameWorld::ShowLocation(int aPlayerLocation)
{
	string lLocation;
	try {
		lLocation = fLocations.at(aPlayerLocation);
		cout << "You find yourself: " << fLocations.at(aPlayerLocation) << ". You can go:" << endl;
		ShowValidMoves(aPlayerLocation);
		return;
	}
	catch(exception e){
		cout << "You cannot go that way!" << endl;
	}
	
	

	
}

void GameWorld::ShowVisibleItems(int aPlayerLocation)
{
	cout << "You look around and see:" << endl;
	for each (string s in fLocationItems[aPlayerLocation])
		cout << s << endl;
	{

	}
}

int GameWorld::ValidateMove(int aPlayerLocation, string aMove)
{
	for each (pair<int,string> p in fWorldMap.getConnections(aPlayerLocation))
	{
		string lDirection = p.second;
		transform(lDirection.begin(), lDirection.end(), lDirection.begin(), tolower);
		if (aMove.find(lDirection) != string::npos)
			return p.first;
	}
	return aPlayerLocation;
}

void GameWorld::AddLocation(string aLocationName, list<pair<int, string>> aPaths)
{
	fLocations.push_back(aLocationName);

	for each (pair<int,string> p  in aPaths)
	{
		fWorldMap.addConnection(fLocations.size()-1, p);
	}
}

void GameWorld::AddItemToLocation(string aLocationName, string aItemName)
{
	int i = 0;
	for each (string s in fLocations)
	{
		if (s.compare(aLocationName) == 0) {
			fLocationItems[i].push_back(aItemName);
			break;
		}
		i++;
	}
}

