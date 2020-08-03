#include "Screen.h"

Screen::Screen() :
    mWindow(nullptr),
    mRenderer(nullptr),
    isRunning(true),
    box(),
    line()
{
}

bool Screen::initScreen()
{
    // check SDL initialzation
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    // create the window
    mWindow = SDL_CreateWindow(
        "Ping Pong",                       // title
        SDL_WINDOWPOS_UNDEFINED,           // x position
        SDL_WINDOWPOS_UNDEFINED,           // y position
        WIDTH,                             // width
        HEIGHT,                            // height
        SDL_WINDOW_OPENGL                  // flag
    );

    // check window creating
    if (mWindow == NULL)
    {
        SDL_Log("Unable to create SDL window: %s", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(
        mWindow,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (mRenderer == NULL)
    {
        SDL_Log("Unable to create SDL renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Screen::closeScreen()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Screen::runScreen()
{
    while (isRunning)
    {
        processInput();
        updateScreen();
        renderScreen();
    }
}

void Screen::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        }
    }
}

void Screen::updateScreen()
{
    
}

void Screen::renderScreen()
{
    // set background color
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);

    // draw line on screen using DDA algorithm
    line.drawLineDDA(50, 40, 50, 400, mRenderer);

    // draw line on screen using Bresenham algorithm
    line.drawLineBresenham(50, 50, 300, 500, mRenderer);

    // present the render on the screen
    SDL_RenderPresent(mRenderer);
}
