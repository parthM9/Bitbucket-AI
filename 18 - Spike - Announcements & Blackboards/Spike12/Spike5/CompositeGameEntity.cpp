#include "CompositeGameEntity.h"
#include <iostream>
#include "GameEntity.h"

CompositeGameEntity::CompositeGameEntity(){}


CompositeGameEntity::CompositeGameEntity(string aName, string aDescription)
{
	fDescription = aDescription;
	fName = aName;
	fEntities = list<Entity*>(0);
}


CompositeGameEntity::~CompositeGameEntity()
{
}

void CompositeGameEntity::display()
{
	cout << fDescription << endl;
}

void CompositeGameEntity::displayAll()
{
	for each (Entity* e in fEntities)
	{
		if (e != nullptr)
			cout << e->getName() << endl;
	}
}

bool CompositeGameEntity::add(Entity* aEntity)
{
	fEntities.push_back(aEntity);
	return true;
}

void CompositeGameEntity::remove(Entity* aEntity)
{
	fEntities.remove(aEntity);
	
}

string CompositeGameEntity::getName()
{
	return fName;
}

list<Entity*> CompositeGameEntity::getEntities()
{
	return fEntities;
}