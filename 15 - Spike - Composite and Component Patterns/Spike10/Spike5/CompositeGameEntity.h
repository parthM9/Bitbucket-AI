#pragma once
#include "Entity.h"
#include <list>



class CompositeGameEntity : public Entity
{
public:
	CompositeGameEntity();
	CompositeGameEntity(string aName, string aDescription);
	~CompositeGameEntity();

	virtual void display();
	virtual string getName();
	void displayAll();

	bool add(Entity* aEntity);
	void remove(Entity* aEntity);

	list<Entity*> getEntities();

private:
	list<Entity*> fEntities;
};

