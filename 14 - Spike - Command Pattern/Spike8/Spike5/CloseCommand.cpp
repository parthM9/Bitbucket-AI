#include "CloseCommand.h"
#include <iostream>

using namespace std;


CloseCommand::CloseCommand()
{
}


CloseCommand::~CloseCommand()
{
}

void CloseCommand::execute() {
	cout << "Close Command" << endl;
}