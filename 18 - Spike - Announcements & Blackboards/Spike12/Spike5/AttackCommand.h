#pragma once
#include "Command.h"
class AttackCommand : public Command
{
public:
	AttackCommand();
	~AttackCommand();

	virtual void execute();
};

