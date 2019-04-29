//Program colors patches where trees were present during the simulation
//Several Files are availble in the Input folder to play around with, simply type name of file when prompted

// to compile-> g++ main.cpp Display.cpp World.cpp -o main -lSDL2 -std=gnu++0x
// our bash PatchDisplay

#include <iostream>
#include <string>
#include "Display.h"

using namespace std;

Display * display;

int main(int argc, char** argv)
{
  display = new Display();

  display->initDisplay("Patch Display", 500, 0, 800, 800, true);

  while(display->running())
  {
    display->updateDisplay();
    display->renderDisplay();
    display->renderPresent();
    display->clearRenderer();
    display->handleEvents();
  }

  display->cleanDisplay();

  return 0;
}
