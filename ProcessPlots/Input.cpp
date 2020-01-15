#include "Input.h"

Input::Input()
{
  cout << "Input class has been created! " << endl;
}

Input::~Input()
{

}

void Input::setPlot(int plot)
{
  _plot = plot;
}

void Input::setDirectories()
{
  cout << "Set Directory: ";
  cin >> _directory;

  cout << endl << "Set plot: ";
  cin >> _plot;

  cout << "Set to: " << _directory << endl;
  cout << "Reading files from plot " << getPlot() << endl;
}

void Input::readFile(string filename)
{
  int year, elm, pine, oak, alder, hazel, ash, lime, birch;

  file.open(filename);
  // store to array then close file

  while(file >> year >> elm >> pine >> oak >> alder >> hazel >> ash >> lime >> birch)
  {
    elmCount.push_back(elm);
    pineCount.push_back(pine);
    oakCount.push_back(oak);
    alderCount.push_back(alder);
    hazelCount.push_back(hazel);
    ashCount.push_back(ash);
    limeCount.push_back(lime);
    birchCount.push_back(birch);
  }

  file.close();
}

void Input::allFiles(int nfiles)
{

  string dir = "Input/";
  string part1 = to_string(_plot);
  string part2 = "-";
  string part3 = ".txt";

  for(int i = 1; i < (nfiles+1); i++)
  {
    readFile(dir+part1+part2+to_string(i)+part3);
  }
}

void Input::mergeFiles(int nfiles)
{
  float elm = 0;
  float pine = 0;
  float oak = 0;
  float alder = 0;
  float hazel = 0;
  float ash = 0;
  float lime = 0;
  float birch = 0;

  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < nfiles; j++)
    {
      elm = elm + elmCount[i+(30*j)];
    }

    elm = elm / nfiles;

    elmSum.push_back(elm);

    elm = 0;
  }

  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < nfiles; j++)
    {
      pine = pine + pineCount[i+(30*j)];
    }

    pine = pine / nfiles;

    pineSum.push_back(pine);

    pine = 0;
  }

  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < nfiles; j++)
    {
      oak = oak + oakCount[i+(30*j)];
    }

    oak = oak / nfiles;

    oakSum.push_back(oak);

    oak = 0;
  }

  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < nfiles; j++)
    {
      alder = alder + alderCount[i+(30*j)];
    }

    alder = alder / nfiles;

    alderSum.push_back(alder);

    alder = 0;
  }

  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < nfiles; j++)
    {
      hazel = hazel + hazelCount[i+(30*j)];
    }

    hazel = hazel / nfiles;

    hazelSum.push_back(hazel);

    hazel = 0;
  }

  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < nfiles; j++)
    {
      ash = ash + ashCount[i+(30*j)];
    }

    ash = ash / nfiles;

    ashSum.push_back(ash);

    ash = 0;
  }

  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < nfiles; j++)
    {
      lime = lime + limeCount[i+(30*j)];
    }

    lime = lime / nfiles;

    limeSum.push_back(lime);

    lime = 0;
  }

  for(int i = 0; i < 30; i++)
  {
    for(int j = 0; j < nfiles; j++)
    {
      birch = birch + birchCount[i+(30*j)];
    }

    birch = birch / nfiles;

    birchSum.push_back(birch);

    birch = 0;
  }
}

void Input::testVector()
{
  int counter = 0;
  cout << "Vector size = " << hazelCount.size() << endl;

  for(int i = 0; i < hazelCount.size(); i++)
  {
    cout << hazelCount[i] << endl;
    counter++;
  }

  cout << "Number of 30 values = " << counter << endl;

  for(int i = 0; i < hazelSum.size(); i++)
  {
    cout << hazelSum[i] << endl;
  }

}

void Input::readOut(string filename)
{
  outFile.open("Output/"+filename);

  for(int i = 0; i < 30; i++)
  {
    if(i == 0)
    {
      outFile << "Elm" << ", ";
      outFile << "Pine" << ", ";
      outFile << "Oak" << ", ";
      outFile << "Alder" << ", ";
      outFile << "Hazel" << ", ";
      outFile << "Ash" << ", ";
      outFile << "Lime" << ", ";
      outFile << "Birch" << " " << endl;
    }

    outFile << elmSum[i] << ", ";
    outFile << pineSum[i] << ", ";
    outFile << oakSum[i] << ", ";
    outFile << alderSum[i] << ", ";
    outFile << hazelSum[i] << ", ";
    outFile << ashSum[i] << ", ";
    outFile << limeSum[i] << ", ";
    outFile << birchSum[i] << " " << endl;
  }

  outFile.close();
}

int Input::getPlot()
{
  return _plot;
}

void Input::clearVectors()
{
  elmCount.clear();
  pineCount.clear();
  oakCount.clear();
  alderCount.clear();
  hazelCount.clear();
  ashCount.clear();
  limeCount.clear();
  birchCount.clear();

  elmSum.clear();
  pineSum.clear();
  oakSum.clear();
  alderSum.clear();
  hazelSum.clear();
  ashSum.clear();
  limeSum.clear();
  birchSum.clear();
}
