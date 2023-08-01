#include "Entity.h"
#include <iostream>

using namespace std;

Entity::Entity()
{
}

void Entity::display()
{
	throw std::runtime_error("Unimplemented method!");
}

bool Entity::add(Entity * aEntity)
{
	throw std::runtime_error("Unimplemented method!");
	return false;
}

void Entity::remove()
{
	throw std::runtime_error("Unimplemented method!");
}

string Entity::getName()
{
	throw std::runtime_error("Unimplemented method!");
	return string();
}
