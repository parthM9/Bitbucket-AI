#include "Component.h"

Component::Component()
{
//	fRegisteredEntities = list<Entity*>();
}

Component::~Component()
{}

void Component::registerEntity(Entity * aEntity)
{
	fRegisteredEntities.push_back(aEntity);
}

void Component::removeEntity(Entity* aEntity)
{
	fRegisteredEntities.remove(aEntity);
}

list<Entity*> Component::getRegisteredEntities()
{
	return fRegisteredEntities;
}
