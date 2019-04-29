#include "Display.h"

using namespace std;

Display::Display()
{

}

Display::~Display()
{

}

void Display::initDisplay(const char* title, int x, int y, int w, int h, bool isShown)
{

  world = new World();

  world->LoadFile();

  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    cout << endl << "Display initialised . . . " << endl;

    window = SDL_CreateWindow(title, x, y , w, h, SDL_WINDOW_SHOWN);
    if(window)
    {
      cout << "Window created . . . " << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer)
    {
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      cout << "Renderer created . . . " << endl;
    }

    isRunning = true;
  } else {
    isRunning = false;
  }

}

void Display::handleEvents()
{
  SDL_Event e;

  SDL_PollEvent(&e);

  if(e.type == SDL_KEYDOWN)
  {
    if (e.key.keysym.sym == SDLK_RETURN)
    {
      isRunning = false;
    }
  }

  if (e.type == SDL_QUIT)
  {
    isRunning = false;
  }
}

void Display::updateDisplay()
{
  //  drawFunctions->fillCircle(renderer,500,500,10);
//  SDL_RenderPresent(renderer);
    world->DrawMap(renderer);
}

void Display::clearRenderer()
{
  SDL_RenderClear(renderer);
}

void Display::renderDisplay()
{

}

void Display::renderPresent()
{
  SDL_RenderPresent(renderer);
}

void Display::cleanDisplay()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  //delete world;

  cout << "Display cleaned . . . " << endl << endl;
}

bool Display::running()
{
  return isRunning;
}
