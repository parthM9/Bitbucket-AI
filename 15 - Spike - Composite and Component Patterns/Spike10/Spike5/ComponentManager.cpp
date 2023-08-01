#include "ComponentManager.h"



ComponentManager::ComponentManager()
{
	fOpenable_Component = new Openable_Component();
	fTakeable_Component = new Takeable_Component();
}


ComponentManager::~ComponentManager()
{
	delete fOpenable_Component;
	delete fTakeable_Component;
}

void ComponentManager::RegisterEntityWithComponents(list<string> aComponents, Entity* aEntity)
{
	for each (string s in aComponents)
	{
		if (s.compare("Takeable") == 0)
			fTakeable_Component->registerEntity(aEntity);
		else if (s.compare("Openable") == 0)
			fOpenable_Component->registerEntity(aEntity);
	}
}

void ComponentManager::RegisterEntityWithComponent(Component_Types aComponent, Entity* aEntity)
{
	switch (aComponent)
	{
	case Openable:
		fOpenable_Component->registerEntity(aEntity);
		break;

	case Takeable:
		fTakeable_Component->registerEntity(aEntity);
		break;
	}
}

bool ComponentManager::EntityHasComponent(Component_Types aComponent, Entity* aEntity)
{
	switch (aComponent)
	{
	case Openable:
		for each (Entity* e in fOpenable_Component->getRegisteredEntities())
			if (e == aEntity)
				return true;
		return false;
		break;

	case Takeable:
		for each (Entity* e in fTakeable_Component->getRegisteredEntities())
		{
			if (e == aEntity)
				return true;
		}
		return false;		
		break;
	}
}
