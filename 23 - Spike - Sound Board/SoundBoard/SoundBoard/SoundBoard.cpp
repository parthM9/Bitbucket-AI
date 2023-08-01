// SoundBoard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <SDL.h>


Uint32 playsound(const char *lone)
{
	
	SDL_Init(SDL_INIT_AUDIO);
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8 *wavBuffer;

	SDL_LoadWAV(lone, &wavSpec, &wavBuffer, &wavLength);
	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
	int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
	while (wavLength > 0) {
		return deviceId;
	}
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
	return deviceId;

}

int main(int argc, char *argv[])
{
	//SDL_AudioSpec wavSpec = NULL;
	SDL_Window *window = nullptr;
	SDL_Surface *windowSurface = nullptr;
	SDL_Surface *image1 = nullptr;
	SDL_Surface *image2 = nullptr;
	SDL_Surface *image3 = nullptr;
	SDL_Surface *image12 = nullptr;
	SDL_Surface *currentImage = nullptr;
	Uint32 check = 0;
	SDL_Init(SDL_INIT_VIDEO);
	int ch = 1;
						

	window = SDL_CreateWindow("Play Nature sounds", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	windowSurface = SDL_GetWindowSurface(window);
	image12 = SDL_LoadBMP("LAND2.bmp");
	image1 = SDL_LoadBMP("test.bmp");
	image2 = SDL_LoadBMP("test2.bmp");
	image3 = SDL_LoadBMP("test3.bmp");
	currentImage = image12;
	bool c = true;
	bool isRunning = true;
	SDL_Event ev;
	while (isRunning)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			if (ev.type == SDL_QUIT)
				isRunning = false;
			else if (ev.type == SDL_KEYDOWN)
			{
				switch (ev.key.keysym.sym)
				{
				case SDLK_1:

					currentImage = image1;
					if (check > 0)
					{
						SDL_CloseAudioDevice(check);
						check = playsound("forest.wav");

					}
					else
					{
						check = playsound("forest.wav");
					}

					break;
				case SDLK_2:
					currentImage = image2;
					if (check > 0)
					{
						SDL_CloseAudioDevice(check);
						check = playsound("thunder.wav");

					}
					else
					{
						check = playsound("thunder.wav");
					}
					
					break;
				case SDLK_3:
					currentImage = image3;
					if (check > 0)
					{
						SDL_CloseAudioDevice(check);
						check = playsound("wind.wav");

					}
					else
					{
						check = playsound("wind.wav");
					}
					break;
				case SDLK_0:
					
					if (check > 0)
					{
						if (c == true)
							ch = 1;
						else
							ch = 0;
						SDL_PauseAudioDevice(check, c);
						c = !c;
					}
					break;
				}
			}
		}
		SDL_BlitSurface(currentImage, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}
	SDL_FreeSurface(image12);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	SDL_FreeSurface(image3);
	SDL_DestroyWindow(window);
	currentImage = image1 = image2 = image3 = nullptr;
	window = nullptr;
	SDL_Quit();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
