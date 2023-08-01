#pragma once
#include <vector>
#include "Entity.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void CheckInventory();
	void AddItemToInventory(Entity* aItem);
	Entity* RemoveItemFromInventory(Entity* aItem);
	vector<Entity*> GetInventory();
	
	int getLocation();
	void setLocation(int aLocation);

private:
	vector<Entity*> fInventory;
	int fLocation;
};

