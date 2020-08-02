#include "Box.h"

Box::Box() :
    mBox()
{
}

void Box::plot_box_ndc(double ndcX, double ndcY, int rWidth, int rHight, SDL_Renderer* mRenderer)
{
    double wdcX = ndcX * (WIDTH / 2.0) + (WIDTH / 2.0);
    double wdcY = ndcY * (HEIGHT / 2.0) + (HEIGHT / 2.0);

    mBox.x = (int)floor(wdcX);
    mBox.y = (int)floor(wdcY);
    mBox.w = rWidth;
    mBox.h = rHight;

    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(mRenderer, &mBox);
}
