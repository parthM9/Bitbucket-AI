#include "pch.h"
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

SDL_Texture *LoadTexture(std::string filePath, SDL_Renderer *renderTarget)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *surface = IMG_Load(filePath.c_str());
	if (surface == NULL)
		std::cout << "Error" << std::endl;
	else
	{
		texture = SDL_CreateTextureFromSurface(renderTarget, surface);
		if (texture == NULL)
			std::cout << "Error" << std::endl;
	}

	SDL_FreeSurface(surface);

	return texture;
}

int main(int argc, char *argv[])
{
	// Initializing and loading variables
	SDL_Window *window = nullptr;
	SDL_Texture *currentImage = nullptr;
	SDL_Renderer *renderTarget = nullptr;

	SDL_Rect playerRect;

	int frameWidth, frameHeight;
	int textureWidth, textureHeight;


	SDL_Init(SDL_INIT_VIDEO);

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (IMG_Init(imgFlags) != imgFlags)
		std::cout << "Error: " << IMG_GetError() << std::endl;
	SDL_Rect cameraRect = { 0,0,640,480 };
	window = SDL_CreateWindow("Sprites", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture = LoadTexture("LAND2.bmp", renderTarget);
	currentImage = LoadTexture("image.png", renderTarget);

	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);

	frameWidth = textureWidth / 3;
	frameHeight = textureHeight / 4;

	playerRect.x = playerRect.y = 0;
	playerRect.w = frameWidth;
	playerRect.h = frameHeight;
	int ph1 = 0;
	int ph2 = 0;
	int ph3 = 0;
	int bh = 0;


	bool isRunning = true;
	SDL_Event ev;

	while (isRunning)
	{
		while (SDL_PollEvent(&ev) != 0)
		{
			// Getting the events
			if (ev.type == SDL_QUIT)
				isRunning = false;
			else if (ev.type == SDL_KEYDOWN)
			{
				switch (ev.key.keysym.sym)
				{
				case SDLK_1:
					if (bh > 0)
					{
						SDL_RenderCopy(renderTarget, texture, &cameraRect, NULL);
						SDL_RenderPresent(renderTarget);
						bh = -1;
					}

					if (ph1 == 0)
					{

						playerRect.y = 0;
						SDL_Rect playerPosition;
						playerPosition.x = playerPosition.y = 200;
						playerPosition.w = playerPosition.h = 32;

						SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
						SDL_RenderPresent(renderTarget);
						ph1 = 1;
					}
					else {
						SDL_RenderClear(renderTarget);
						if (bh > 0 || bh == -1)
						{
							SDL_RenderCopy(renderTarget, texture, &cameraRect, NULL);
						}
						if (ph2 == 1)
						{
							playerRect.y = 32;
							SDL_Rect playerPosition1;
							playerPosition1.x = playerPosition1.y = 0;
							playerPosition1.w = playerPosition1.h = 32;
							//SDL_RenderClear(renderTarget);
							SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition1);
							//SDL_RenderPresent(renderTarget);
						}
						if (ph3 == 1)
						{
							playerRect.y = 64;
							SDL_Rect playerPosition2;
							playerPosition2.x = playerPosition2.y = 400;
							playerPosition2.w = playerPosition2.h = 32;
							//SDL_RenderClear(renderTarget);
							SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition2);
							//SDL_RenderPresent(renderTarget);
						}
						SDL_RenderPresent(renderTarget);

						ph1 = 0;
					}

					break;
				case SDLK_2:
					if (bh > 0)
					{
						SDL_RenderCopy(renderTarget, texture, &cameraRect, NULL);
						bh = -1;
					}
					if (ph2 == 0)
					{

						playerRect.y = 32;
						SDL_Rect playerPosition1;
						playerPosition1.x = playerPosition1.y = 0;
						playerPosition1.w = playerPosition1.h = 32;
						//SDL_RenderClear(renderTarget);
						SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition1);
						SDL_RenderPresent(renderTarget);
						ph2 = 1;
					}
					else {
						SDL_RenderClear(renderTarget);
						if (bh > 0 || bh == -1)
						{
							SDL_RenderCopy(renderTarget, texture, &cameraRect, NULL);
						}
						if (ph1 == 1)
						{
							playerRect.y = 0;
							SDL_Rect playerPosition;
							playerPosition.x = playerPosition.y = 200;
							playerPosition.w = playerPosition.h = 32;

							SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
							//SDL_RenderPresent(renderTarget);

						}
						if (ph3 == 1)
						{
							playerRect.y = 64;
							SDL_Rect playerPosition2;
							playerPosition2.x = playerPosition2.y = 400;
							playerPosition2.w = playerPosition2.h = 32;
							//SDL_RenderClear(renderTarget);
							SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition2);
							//SDL_RenderPresent(renderTarget);
						}
						SDL_RenderPresent(renderTarget);
						ph2 = 0;
					}

					break;
				case SDLK_3:

					if (bh > 0)
					{
						SDL_RenderCopy(renderTarget, texture, &cameraRect, NULL);
						bh = -1;
					}
					if (ph3 == 0)
					{

						playerRect.y = 64;
						SDL_Rect playerPosition2;
						playerPosition2.x = playerPosition2.y = 400;
						playerPosition2.w = playerPosition2.h = 32;
						//SDL_RenderClear(renderTarget);
						SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition2);
						SDL_RenderPresent(renderTarget);
						ph3 = 1;
					}
					else {
						SDL_RenderClear(renderTarget);
						if (bh > 0 || bh == -1)
						{
							SDL_RenderCopy(renderTarget, texture, &cameraRect, NULL);
						}
						if (ph1 == 1)
						{
							playerRect.y = 0;
							SDL_Rect playerPosition;
							playerPosition.x = playerPosition.y = 200;
							playerPosition.w = playerPosition.h = 32;

							SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
							//SDL_RenderPresent(renderTarget);

						}
						if (ph2 == 1)
						{
							playerRect.y = 32;
							SDL_Rect playerPosition1;
							playerPosition1.x = playerPosition1.y = 0;
							playerPosition1.w = playerPosition1.h = 32;
							//SDL_RenderClear(renderTarget);
							SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition1);
							//SDL_RenderPresent(renderTarget);
						}

						SDL_RenderPresent(renderTarget);
						ph3 = 0;
					}
					break;
				case SDLK_0:
					if (bh == 0)
					{
						SDL_RenderCopy(renderTarget, texture, &cameraRect, NULL);
						bh = 1;
					}
					else
					{
						SDL_RenderClear(renderTarget);
						bh = 0;
					}

					if (ph1 == 1)
					{
						playerRect.y = 0;
						SDL_Rect playerPosition;
						playerPosition.x = playerPosition.y = 200;
						playerPosition.w = playerPosition.h = 32;

						SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition);
						//SDL_RenderPresent(renderTarget);

					}
					if (ph2 == 1)
					{
						playerRect.y = 32;
						SDL_Rect playerPosition1;
						playerPosition1.x = playerPosition1.y = 0;
						playerPosition1.w = playerPosition1.h = 32;
						//SDL_RenderClear(renderTarget);
						SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition1);
						//SDL_RenderPresent(renderTarget);
					}
					if (ph3 == 1)
					{
						playerRect.y = 64;
						SDL_Rect playerPosition2;
						playerPosition2.x = playerPosition2.y = 400;
						playerPosition2.w = playerPosition2.h = 32;
						//SDL_RenderClear(renderTarget);
						SDL_RenderCopy(renderTarget, currentImage, &playerRect, &playerPosition2);
						//SDL_RenderPresent(renderTarget);
					}
					SDL_RenderPresent(renderTarget);
					break;
				}
			}

		}




	}

	SDL_DestroyWindow(window);
	SDL_DestroyTexture(currentImage);
	SDL_DestroyRenderer(renderTarget);
	SDL_DestroyTexture(texture);
	window = nullptr;
	currentImage = nullptr;
	renderTarget = nullptr;

	SDL_Quit();

	return 0;
}
