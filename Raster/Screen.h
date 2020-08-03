#pragma once
#include "SDL.h"
#include "Constants.h"
#include "Pixel.h"
#include "Box.h"
#include "Line.h"

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
	Box box;
	Line line;
};

