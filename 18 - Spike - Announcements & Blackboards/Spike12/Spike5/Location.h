#pragma once
#include "CompositeGameEntity.h"
#include <string>
class Location :
	public CompositeGameEntity
{
public:
	Location();
	Location(string aName, string aDescription);
	~Location();



private:
	string fName;
	string fDescription;

};

