#include "WorldProcessor.h"
#include <cstdlib>
#include "Entity.h"
#include "GameEntity.h"
#include "CompositeGameEntity.h"




WorldProcessor::WorldProcessor()
{
	fGameWorld = new GameWorld();
}


WorldProcessor::~WorldProcessor()
{
}

GameWorld* WorldProcessor::loadWorld(string aString)
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
				loadLocations();
			}
			else if (s.compare("Item") == 0)
			{
				loadItems();
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

void WorldProcessor::loadLocations()
{
	string s;
	string lLocationName = "";
	string lLocationDesc = "";
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

	s = getAttribute();
	}

	//Get Description

	if (s.compare("Description") == 0)
	{
		while (lNewChar != '\n') {
			if (lNewChar != '\0')
				lLocationDesc += lNewChar;
			lNewChar = fInputFile.get();
		}
		s = getAttribute();

	}


	//Get Connections
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
		s = getAttribute();

	}

	//Get Directions
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

	Location* newLocation = new Location(lLocationName, lLocationDesc);

	fGameWorld->AddLocation(newLocation, lConnections);
}

void WorldProcessor::loadItems()
{
	pair<string, Entity*> p = getItem();
	fGameWorld->AddItemToLocation(p.first,p.second);
}

pair<string,Entity*> WorldProcessor::getItem()
{
	string s;
	string lContainer = "";
	string lItemDesc = "";
	string lLocationName = "";
	string lItemName = "";
	string lNumItems = "";
	char lNewChar = '\0';
	string lComponent = "";
	list<string> lComponents = list<string>();

	//Get Name
	s = getAttribute();
	if (s.compare("Name") == 0)
	{
		while (lNewChar != '\n') {
			if (lNewChar != '\0')
				lItemName += lNewChar;
			lNewChar = fInputFile.get();
		}
		s = getAttribute();
		lNewChar = fInputFile.get();
	}

	//Get Description
	if (s.compare("Description") == 0)
	{
		while (lNewChar != '\n') {
			if (lNewChar != '\0')
				lItemDesc += lNewChar;
			lNewChar = fInputFile.get();
		}
		s = getAttribute();

	}

	//Get Components
	if (s.compare("Components") == 0)
	{
		lNewChar = '\0';
		while (lNewChar != '\n') {
			string lComponent = "";

			while (lNewChar != ',')
			{
				if (lNewChar != '\0') {
					lComponent += lNewChar;
				}
				lNewChar = fInputFile.get();
			}
			lComponents.push_back(lComponent);
			lNewChar = fInputFile.get();
		}
		s = getAttribute();
	}

	
	//Get Location
	if (s.compare("ItemLocation") == 0)
	{
		lNewChar = '\0';
		while (lNewChar != '\n') {
			
			while (lNewChar != ',')
			{
				if (lNewChar != '\0') {
					lLocationName += lNewChar;
				}
				lNewChar = fInputFile.get();
			}
			lNewChar = fInputFile.get();
		}
		s = getAttribute();

	}


	//Get Container
	if (s.compare("Container") == 0)
	{
		lNewChar = '\0';
		while (lNewChar != '\n') {

			while (lNewChar != ',')
			{
				if (lNewChar != '\0') {
					lContainer += lNewChar;
				}
				lNewChar = fInputFile.get();
			}
			lNewChar = fInputFile.get();
		}
		s = getAttribute();
	}

	//Get NumItems
	if (s.compare("NumItems") == 0)
	{
		lNewChar = '\0';
		while (lNewChar != '\n') {

			while (lNewChar != ',')
			{
				if (lNewChar != '\0') {
					lNumItems += lNewChar;
				}
				lNewChar = fInputFile.get();
			}
			lNewChar = fInputFile.get();
		}
	}

	Entity* newEntity;

	if (lContainer.compare("True") == 0)
	{
		newEntity = new CompositeGameEntity(lItemName, lItemDesc);
		fGameWorld->RegisterEntityComponents(lComponents, newEntity);
		for (int i = 0; i < stoi(lNumItems); i++)
		{
			newEntity->add(getItem().second);
		}
		pair<string, Entity*> p = { lLocationName,newEntity };
		return p;
	}
	else
	{
		newEntity = new GameEntity(lItemName, lItemDesc);
		fGameWorld->RegisterEntityComponents(lComponents, newEntity);
		pair<string, Entity*> p = { lLocationName,newEntity };
		return p;
	}

}

