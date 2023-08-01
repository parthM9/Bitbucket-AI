#include "DropCommand.h"
#include <iostream>

using namespace std;

DropCommand::DropCommand()
{
}


DropCommand::~DropCommand()
{
}

void DropCommand::execute() {
	cout << "Drop Command" << endl;
}