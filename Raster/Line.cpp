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

void Line::drawLineBresenham(int x1, int y1, int x2, int y2, SDL_Renderer* mRenderer)
{
	int x, y, deltaX, deltaY, p;

	x = x1;
	y = y1;

	deltaX = x2 - x1;
	deltaY = y2 - y1;

	p = (2 * deltaX) - deltaY;

	while (x <= x2)
	{
		pixel.plot_pixel_wdc(x, y, mRenderer);
		x++;

		if (p < 0)
		{
			p += 2 * deltaY;
		}
		else
		{
			p += (2 * deltaY) - (2 * deltaX);
			y++;
		}
	}
}
