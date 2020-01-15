#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Input
{
public:
  Input();
  ~Input();
  void setDirectories();
  void readFile(string filename);
  void allFiles(int nfiles); //iterates through calls of the readFile function
  void mergeFiles(int nfiles);
  void clearVectors();
  void testVector();
  void readOut(string filename);

  void setPlot(int plot);

  int getPlot();

private:
  string _directory;
  ifstream file;
  ofstream outFile;

  int fileCount; // stores the iterated for how many files have been read in
  int _plot; // to specifiy which plot files need to be processed

  vector <int> elmCount; // acumulates populations from each file
  vector <int> pineCount;
  vector <int> oakCount;
  vector <int> alderCount;
  vector <int> hazelCount;
  vector <int> ashCount;
  vector <int> limeCount;
  vector <int> birchCount;

  vector <float> elmSum; // sum across all plots
  vector <float> pineSum;
  vector <float> oakSum;
  vector <float> alderSum;
  vector <float> hazelSum;
  vector <float> ashSum;
  vector <float> limeSum;
  vector <float> birchSum;

};

#endif
