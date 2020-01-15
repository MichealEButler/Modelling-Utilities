// program process all output files for each plot to average population values for species
// g++ main.cpp Input.cpp -o main -std=gnu++0x

#include <iostream>
#include "Input.h"

Input* input;

using namespace std;

int main()
{

  input = new Input();

  for(int i = 0; i < 16; i++)
  {
    input->setPlot(i+1);
    input->allFiles(20);
    input->mergeFiles(20);
    input->testVector();
    input->readOut("plot" + to_string(i+1) + ".txt");
    input->clearVectors();
  }

  cout << "Initial program has compiled! " << endl;

  delete input;

  return 0;
}
