#pragma once
#include "SDL.h"
#include "Constants.h"

class Box
{
public:
	// constructor
	Box();

	// public functions
	void plot_box_ndc(double ndcX, double ndcY, int rWidth, int rHight, SDL_Renderer* mRenderer);

private:
	// private functions

	// private variable
	SDL_Rect mBox;

	// logic varaiables
};

