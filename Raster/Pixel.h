#pragma once
#include "SDL.h"
#include "Constants.h"

class Pixel
{
public:
	// public functions
	void plot_pixel_ndc(float ndcX, float ndcY, SDL_Renderer* mRenderer);
	void plot_pixel_wdc(int wdcX, int wdcY, SDL_Renderer* mRenderer);

private:
	// private functions

	// private variable

	// logic varaiables
};

