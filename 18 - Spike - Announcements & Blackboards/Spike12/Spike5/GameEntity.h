#pragma once
#include "Entity.h"
class GameEntity : public Entity
{
public:
	GameEntity(string aName, string aDescription);
	~GameEntity();

	virtual void display();
	virtual string getName();
	virtual bool add(GameEntity* aGameEntity);
};

