#pragma once
#include "Command.h"
class OpenCommand :
	public Command
{
public:
	OpenCommand();
	~OpenCommand();

	virtual void execute();
};

