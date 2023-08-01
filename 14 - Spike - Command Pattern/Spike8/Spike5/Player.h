#pragma once
#include <vector>

using namespace std;

class Player
{
public:
	Player();
	~Player();
	void CheckInventory();
	void AddItemToInventory(string aItem);
	void RemoveItemFromInventory(string aItem);
	
	int getLocation();
	void setLocation(int aLocation);

private:
	vector<string> fInventory;
	int fLocation;
};

