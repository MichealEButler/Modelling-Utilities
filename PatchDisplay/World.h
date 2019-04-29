#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <fstream>
#include <string>
#include <SDL2/SDL.h>

using namespace std;

class World
{
public:
  World();
  ~World();
  void LoadFile();
  void DrawMap(SDL_Renderer* renderer);
  void fillRect(SDL_Renderer * renderer, int x, int y, int width, int height);

private:
  int world[100][100];

};

#endif
