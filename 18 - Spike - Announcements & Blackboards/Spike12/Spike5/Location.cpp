#include "Location.h"


Location::Location()
{}

Location::Location(string aName, string aDescription) : CompositeGameEntity(aName,aDescription)
{
	fName = aName;
	fDescription = aDescription;
}


Location::~Location()
{
}

