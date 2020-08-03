#include "Line.h"

Pixel pixel;

void Line::drawLineDDA(int x1, int y1, int x2, int y2, SDL_Renderer* mRenderer)
{
	int deltaX, deltaY, steps, nextX, nextY;

	deltaX = abs(x2 - x1);
	deltaY = abs(y2 - y1);

	if (deltaX > deltaY) { steps = deltaX; }
	else { steps = deltaY; }

	nextX = deltaX / steps;
	nextY = deltaY / steps;

	for (int i = 0; i < steps; i++)
	{
		pixel.plot_pixel_wdc(x1, y1, mRenderer);

		x1 += nextX;
		y1 += nextY;
	}


 }
