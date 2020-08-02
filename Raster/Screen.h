#pragma once
#include "SDL.h"

class Screen
{
public:
	// constructor
	Screen();

	// public functions
	void initScreen();
	void closeScreen();
	void runScreen();

private:
	// private functions
	void updateScreen();
	void renderScreen();

	// private variables
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	// logic variables
	bool isRunning;
};

