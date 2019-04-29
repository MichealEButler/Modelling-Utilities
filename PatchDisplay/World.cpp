#include "World.h"

World::World()
{

}

World::~World()
{

}

void World::LoadFile()
{
  string inputFile;
  string folder = "Input/";
  int element;
  cout << "Open: ";
  cin >> inputFile;
  cout << endl;
  ifstream file (folder + inputFile);
  file.is_open();

  for (int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      file >> element;
      world[i][j] = element;
    }
  }

  file.close();
}

void World::DrawMap(SDL_Renderer* renderer)
{
  int type = 0;

  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++)
    {
      type = world[i][j];

      if(type == 0)
      {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        fillRect(renderer, i*8, j*8, 8, 8);
      }
      if (type == 1)
      {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        fillRect(renderer, i*8, j*8, 8, 8);
      }
    }
  }
}

void World::fillRect(SDL_Renderer * renderer, int x, int y, int width, int height)
{
  int x2 = x + width;
  int y2 = y + height;

  if (x < 0) x = 0;
  if(x >= 800) x = 800;
  if (y < 0) y = 0;
  if(y >= 800) y = 800;

  if (x2 < 0) x2 = 0;
  if(x2 >= 800) x2 = 800;
  if (y2 < 0) y2 = 0;
  if(y >= 800) y2 = 800;

  for(int i = x; i < x2; i++)
  {
    for(int j = y; j < y2; j++)
    {
      SDL_RenderDrawPoint(renderer, i, j);
    }
  }
}
