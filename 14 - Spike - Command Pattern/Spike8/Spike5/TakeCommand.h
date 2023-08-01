#pragma once
#include "Command.h"
class TakeCommand :
	public Command
{
public:
	TakeCommand();
	~TakeCommand();

	virtual void execute();
};

