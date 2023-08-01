#include <cstdlib>

#include "StateManager.h"


#include "MainMenu.h"
#include "About.h"
#include "Help.h"
#include "HallOfFame.h"
#include "SelectAdventure.h"
#include "Quit.h"
#include "NewHighScore.h"

#include "GameplayVoidWorld.h"

StateManager::StateManager()
{
	fQuitGame = false;
	fCurrentState = 0;
}

void StateManager::SetState(States aState)
{
	if (!fCurrentState)
		delete fCurrentState;

	switch (aState)
	{
	case StateMainMenu:
		fCurrentState = new MainMenu();
		break;
	case StateAbout: 
		fCurrentState = new About();
		break;
	case StateHelp:
		fCurrentState = new Help();
		break;
	case StateHallOfFame:
		fCurrentState = new HallOfFame();
		break;
	case StateNewHighScore:
		fCurrentState = new NewHighScore();
		break;
	case StateSelectAdventure:
		fCurrentState = new SelectAdventure();
		break;
	case StateGameplayVoidWorld:
		fCurrentState = new GameplayVoidWorld();
		break;
	case StateQuit:
		fCurrentState = new Quit();
		fQuitGame = true;
		break;
	default:
		break;

	}
}

void StateManager::run()
{
	while (!fQuitGame)
	{
		//Clear screen
		system("cls");

		SetState(fCurrentState->runState());
	}
}