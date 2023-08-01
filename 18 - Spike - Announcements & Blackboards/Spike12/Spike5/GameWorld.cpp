#include "GameWorld.h"
#include <algorithm>
#include "Location.h"



GameWorld::GameWorld()
{
	fWorldMap = Graph();
	fLocations = vector<Location*>();

	fComponentManager = new ComponentManager();
}


GameWorld::~GameWorld()
{
	for each (Location* l in fLocations)
	{
		delete l;
	}
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
	lLocation = fLocations.at(aPlayerLocation)->getName();
	cout << "You find yourself: " << lLocation << ". You can go:" << endl;
	ShowValidMoves(aPlayerLocation);
	return;
}

void GameWorld::ShowVisibleItems(int aPlayerLocation)
{
	cout << "You look around and see:" << endl;
	fLocations.at(aPlayerLocation)->displayAll();

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

void GameWorld::AddLocation(Location* aLocation, list<pair<int, string>> aPaths)
{
	fLocations.push_back(aLocation);

	for each (pair<int,string> p  in aPaths)
	{
		fWorldMap.addConnection(fLocations.size()-1, p);
	}
}

void GameWorld::AddItemToLocation(string aLocationName, Entity* aGameEntity)
{
	int i = 0;
	for each (Location* l in fLocations)
	{
		if (l->getName().compare(aLocationName) == 0) {
			l->add(aGameEntity);
			break;
		}
		i++;
	}
}

Location* GameWorld::getLocation(int aPlayerLocation)
{
	return fLocations.at(aPlayerLocation);
}

void GameWorld::RegisterEntityComponents(list<string> aComponents, Entity * aEntity)
{
	fComponentManager->RegisterEntityWithComponents(aComponents, aEntity);
}

bool GameWorld::EntityHasComponent(Entity * aEntity, Component_Types aComponent)
{
	return fComponentManager->EntityHasComponent(aComponent, aEntity);
}

