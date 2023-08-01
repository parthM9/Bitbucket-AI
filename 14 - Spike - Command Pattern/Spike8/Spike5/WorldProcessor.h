#pragma once
#include <string>
#include <iostream>
#include <fstream>
	
#include "GameWorld.h"


using namespace std;

class WorldProcessor
{
public:
	WorldProcessor();
	~WorldProcessor();
	
	GameWorld loadWorld(string aWorld);

private:

	ifstream fInputFile;

	bool loadFile(string aWorld);
	void printFile();
	string getAttribute();
	void getLocation();
	void getItem();

	GameWorld fGameWorld;
};

