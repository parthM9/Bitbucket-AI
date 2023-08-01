#pragma once
#include "Entity.h"
#include <list>

using namespace std;

class Component
{
public:
	Component();
	~Component();

	void registerEntity(Entity* aEntity);
	void removeEntity(Entity* aEntity);
	list<Entity*> getRegisteredEntities();

private:
	list<Entity*> fRegisteredEntities;
};