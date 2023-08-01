#include "Player.h"
#include <iostream>
#include <string>


Player::Player()
{
	fInventory = vector<string>();
}


Player::~Player()
{
}

void Player::CheckInventory()
{
	if (fInventory.size() == 0)
		cout << "Inventory is empty" << endl;
	else {
		for each (string s in fInventory)
		{
			cout << s << endl;
		}
	}
}

void Player::AddItemToInventory(string aName)
{
	fInventory.push_back(aName);
}

void Player::RemoveItemFromInventory(string aName)
{
	for (int i = 0; i < fInventory.size(); i++)
	{
		if (fInventory[i] == aName) {
			fInventory.erase(fInventory.begin() + i);
			break;
		}
	}
}
