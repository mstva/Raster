#include "Pixel.h"

void Pixel::plot_pixel_ndc(float ndcX, float ndcY, SDL_Renderer* mRenderer)
{

    float wdcX = ndcX * (WIDTH / 2) + (WIDTH / 2);
    float wdcY = ndcY * (HEIGHT / 2) + (HEIGHT / 2);

    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(mRenderer, (int)wdcX, (int)wdcY);
}

void Pixel::plot_pixel_wdc(int wdcX, int wdcY, SDL_Renderer* mRenderer)
{
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(mRenderer, wdcX, wdcY);
}
