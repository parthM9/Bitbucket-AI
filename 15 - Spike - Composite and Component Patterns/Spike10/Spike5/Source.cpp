#include "StateManager.h"
#include "CommandProcessor.h"
using namespace std;

int main()
{
	StateManager SM;
	SM.SetState(StateMainMenu);



	SM.run();
	
	return 0;
}