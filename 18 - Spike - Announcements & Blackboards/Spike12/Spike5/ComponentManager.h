#pragma once
#include "GameComponents.h"
class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();
	
	void RegisterEntityWithComponents(list<string> aComponents, Entity* aEntity);
	void RegisterEntityWithComponent(Component_Types aComponent, Entity* aEntity);
	bool EntityHasComponent(Component_Types aComponent, Entity* aEntity);

private:
	Openable_Component* fOpenable_Component;
	Takeable_Component* fTakeable_Component;
};

