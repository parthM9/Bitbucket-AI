#include "Player.h"
#include <iostream>
#include <string>


Player::Player()
{
	fInventory = vector<Entity*>();
	fLocation = 0;
}


Player::~Player()
{
}

void Player::CheckInventory()
{
	if (fInventory.size() == 0)
		cout << "Inventory is empty" << endl;
	else {
		for each (Entity* e in fInventory)
		{
			cout << e->getName() << endl;
		}
	}
}

void Player::AddItemToInventory(Entity* aEntity)
{
	fInventory.push_back(aEntity);
}

Entity* Player::RemoveItemFromInventory(Entity* aEntity)
{
	Entity* result = aEntity;

	for (int i = 0; i < fInventory.size(); i++)
	{
		if (fInventory[i]->getName().compare(aEntity->getName()) == 0) {
			result = fInventory.at(i);
			fInventory.erase(fInventory.begin() + i);
		}
	}
	return result;
}

vector<Entity*> Player::GetInventory()
{
	return fInventory;
}

int Player::getLocation()
{
	return fLocation;
}

void Player::setLocation(int aLocation)
{
	fLocation = aLocation;
}
