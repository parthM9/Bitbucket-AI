#pragma once
#include "Command.h"
class DropCommand :
	public Command
{
public:
	DropCommand();
	~DropCommand();

	virtual void execute();
};

