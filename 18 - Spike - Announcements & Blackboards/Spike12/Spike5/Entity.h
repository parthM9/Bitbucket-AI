#pragma once
#include <string>
#include <list>
#include "Messageable_Entity.h"

using namespace std;

class Entity : public Messageable_Entity {

public:
	Entity();
	virtual void display();

	virtual bool add(Entity* aEntity);
	virtual void remove();

	virtual string getName();




	
protected:
	string fDescription;
	string fName;
	
};