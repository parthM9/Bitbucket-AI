#include "WorldProcessor.h"
#include <cstdlib>



WorldProcessor::WorldProcessor()
{
	fGameWorld = GameWorld();
}


WorldProcessor::~WorldProcessor()
{
}

GameWorld WorldProcessor::loadWorld(string aString)
{

	fInputFile.open(aString);
	if (fInputFile.is_open())
	{
		while (1)
		{
			string s = getAttribute();
			if (s.compare("EOF") == 0)
				break;
			else if (s.compare("Location") == 0)
			{
				getLocation();
			}
		}
	}
	return fGameWorld;
}

string WorldProcessor::getAttribute()
{
	string lInput = "";
	char lNewChar = '\0';

	while (lNewChar != '<')
		lNewChar = fInputFile.get();

	lNewChar = fInputFile.get();

	if (lNewChar == '/')
	{
		lNewChar = fInputFile.peek();
		if (lNewChar == '!')
			return "EOF";
		else return "END";
	}

	while (lNewChar != '>')
	{
		lInput += lNewChar;
		lNewChar = fInputFile.get();
		
	}

	return lInput;

}

void WorldProcessor::getLocation()
{
	string s;
	string lLocationName = "";
	vector<int> lNodeIDs = vector<int>();
	vector<string> lDirections = vector<string>();;
	list<pair<int, string>> lConnections = list<pair<int, string>>();
	char lNewChar = '\0';

	//Get Name
	s = getAttribute();
	if (s.compare("Name") == 0)
	{
		while (lNewChar != '\n') {
			if (lNewChar != '\0')
				lLocationName += lNewChar;
			lNewChar = fInputFile.get();
		}
	}

	//Get Connections
	s = getAttribute();
	if (s.compare("Connections") == 0)
	{
		lNewChar = '\0';
		while (lNewChar != '\n') {
			string lNodeID = "";
			lNodeID += fInputFile.get();
			lNodeID += fInputFile.get();

			lNodeIDs.push_back(stoi(lNodeID));
			lNewChar = fInputFile.get();
		}
	}

	//Get Directions
	s = getAttribute();
	if (s.compare("Directions") == 0)
	{
		lNewChar = '\0';
		while (lNewChar != '\n') {
			string lDirectionName = "";

			while (lNewChar != ',')
			{
				if (lNewChar != '\0') {
					lDirectionName += lNewChar;
				}
				lNewChar = fInputFile.get();
			}
			lDirections.push_back(lDirectionName);
			lNewChar = fInputFile.get();
		}
	}

	for (int i = 0; i < lNodeIDs.size(); i++)
	{
		pair <int, string> p = { lNodeIDs[i], lDirections[i] };
		lConnections.push_back(p);
	}

	fGameWorld.AddLocation(lLocationName, lConnections);
}

/*
GameWorld WorldProcessor::loadWorld(string aString)
{
	GameWorld lGameWorld = GameWorld();

	fInputFile.open(aString);
	string input;
	char newChar;
	if (fInputFile.is_open()) {
			newChar = fInputFile.get();

			if (newChar == '[')
			{

				while (1) 
				{
					string lLocationName;
					list<pair<int, string>> lConnections;
					string lDirection;
					int node;
					
					//Get Location Name
					input = "";
					newChar = fInputFile.get();
					while (newChar != '-') 
					{
						if (newChar == '\n')
						{
							input = "";
							newChar = fInputFile.get();
						
						}
						
						input += newChar;
						newChar = fInputFile.get();
					}
					lLocationName = input;

					if (input[0] == ']')
						break;

					//Get Location Neighbours
					newChar = fInputFile.get();
					while (newChar != '-')
					{
						input = "";
						if (newChar == '\n')
							newChar = fInputFile.get();


						while (newChar != '_')
						{
							input += newChar;
							newChar = fInputFile.get();
						}
						lDirection = input;

						input = "";

						//Get node ID
						input += fInputFile.get();
						input += fInputFile.get();
						node = stoi(input);
						
						//Add to list
						pair<int, string> p = { node, lDirection };
						lConnections.push_back(p);

						//Skip character
						newChar = fInputFile.get();
						newChar = fInputFile.get();

					}
				
					lGameWorld.AddLocation(lLocationName, lConnections);
				}

				
			}
		}

		return lGameWorld;
	
	
}
*/