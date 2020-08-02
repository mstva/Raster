#pragma once
#include "SDL.h"
#include "Constants.h"

class Screen
{
public:
	// constructor
	Screen();

	// public functions
	bool initScreen();
	void closeScreen();
	void runScreen();

private:
	// private functions
	void processInput();
	void updateScreen();
	void renderScreen();

	// private variables
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	// logic variables
	bool isRunning;
};

