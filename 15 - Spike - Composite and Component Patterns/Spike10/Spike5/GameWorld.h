#pragma once
#include "Graph.h"
#include <iostream>
#include <string>
#include "Location.h"
#include "Entity.h"
#include "ComponentManager.h"

class GameWorld
{
public:
	GameWorld();
	~GameWorld();

	void AddLocation(Location* aLocation, list <pair <int, string>> aPaths);
	void AddItemToLocation(string aLocationName, Entity* aGameEntity);


	void PrintWorld();
	void ShowValidMoves(int aPlayerLocation);
	void ShowLocation(int aPlayerLocation);
	void ShowVisibleItems(int aPlayerLocation);
	int ValidateMove(int aPlayerLocation, string aMove);
	Location* getLocation(int aPlayerLocation);
	void RegisterEntityComponents(list<string> aComponents, Entity* aEntity);

	bool EntityHasComponent(Entity* aEntity, Component_Types aComponent);

private:
	Graph fWorldMap;
	vector<Location*> fLocations;
	ComponentManager* fComponentManager;
	
};

