#pragma once
#include "Command.h"
class CloseCommand :
	public Command
{
public:
	CloseCommand();
	~CloseCommand();

	virtual void execute();
};

