#include "GameEntity.h"
#include <iostream>



GameEntity::GameEntity(string aName, string aDescription) 
{
	fDescription = aDescription;
	fName = aName;
}


GameEntity::~GameEntity()
{
}

void GameEntity::display()
{
	cout << fDescription << endl;
}

string GameEntity::getName()
{
	return fName;
}

bool GameEntity::add(GameEntity * aGameEntity)
{
	return false;
}
