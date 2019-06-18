
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const float SINUS = 58.1; // rounded to the nearest one and taken from Botkin 1972
const string directory = "D:/Elm Decline Model/UK Weather Data/Weather Stations/";

float JULMAX;
float JULMIN;
float JANMAX;
float JANMIN;

// PROTOTYPES //
void inputFile(string inFile, string outFile);
void inputPrecip(string inFile, string outFile);
void outputFile(string filename);
void outputDD(string filename, string outFile);
float getAverage(float a, float b);
float calculateDD(float TJan, float TJul); // yearly degree days

int main()
{

	/*
	float testDD1 = calculateDD(17.7, 8.8, 4.4, 0.1);
	cout << "DEGD = " << testDD1 << endl;
	cout << "--------------------------------------" << endl;
	float testDD2 = calculateDD(16.1, 7.1, 4.1, -0.8);
	cout << "DEGD = " << testDD2 << endl;
	cout << "--------------------------------------" << endl;
	float testDD3 = calculateDD(17.4, 8.4, 7.6, 2.5);
	cout << "DEGD = " << testDD3 << endl;
	cout << "--------------------------------------" << endl;
	float testDD4 = calculateDD(18.1, 7.8, 2.0, -1.7);
	cout << "DEGD = " << testDD4 << endl;
	*/

	string folder;
	string file;
	cout << "Set Folder: ";
	cin >> folder;
	cout << "Set File: ";
	cin >> file;

	inputFile((directory+folder+file), directory + folder + "outputAvg.txt");
	inputPrecip((directory+folder+file), directory + folder + "annualRain.txt");
	outputDD(directory + folder + "outputAvg.txt", (directory+folder+"outputDD.txt"));

	system("PAUSE");
	return 0;
}

void inputFile(string inFile, string outFile)
{
	//read in file while extracting january and july temperatures
	// columns set for each input string, a total of at declared due to provisional
	// column for more recent dates (these have been removed from the input files)
	string colA, colB, colC, colD, colE, colF, colG, colH;
	double tMax, tMin;
	int counter = 0;
	int removeLine = 0;

	ifstream file;
	file.open(inFile);

	ofstream outputFile;
	outputFile.open(outFile);

	if (!file)
	{
		cout << "Could not open file to read! " << endl;
	}

	while (file)
	{
		counter++;

		string strInput;

		// removes the first two lines of the input files to allow the columns to be correctly set
		if (removeLine < 1)
		{
			removeLine++;
			getline(file, strInput);
			cout << strInput << endl;
		}

		file >> colA;
		file >> colB;
		file >> colC;
		file >> colD;
		file >> colE;
		file >> colF;
		file >> colG;
		//file >> colH;

		if (counter == 1)
		{
			cout << colA << " " << colB << " " << colC << " " << colD << " " << getAverage(strtof((colC).c_str(), 0), strtof((colD).c_str(), 0)) << endl;
			outputFile << colA << " " << colB << " " << colC << " " << colD << " " << getAverage(strtof((colC).c_str(), 0), strtof((colD).c_str(), 0)) << endl;
		}

		if (counter == 7)
		{
			cout << colA << " " << colB << " " << colC << " " << colD << " " << getAverage(strtof((colC).c_str(), 0), strtof((colD).c_str(), 0)) << endl;
			outputFile << colA << " " << colB << " " << colC << " " << colD << " " << getAverage(strtof((colC).c_str(), 0), strtof((colD).c_str(), 0)) << endl;
		}

		if (counter == 12)
		{
			counter = 0;
		}
		//getline(file, strInput);
		//cout << colC << " " << colD << " "<< endl;
	}

	file.close();
	outputFile.close();

}

void inputPrecip(string inFile, string outFile)
{
	// similar to above function but outputs annual precipitation instead
	string colA, colB, colC, colD, colE, colF, colG, colH;
	int rain = 0;
	int counter = 0;
	int removeLine = 0;

	ifstream file;
	file.open(inFile);

	ofstream outputFile;
	outputFile.open(outFile);

	if (!file)
	{
		cout << "Could not open rain file! " << endl;
	}

	while (file)
	{
		counter++;

		string strInput;

		if (removeLine < 1)
		{
			removeLine++;
			getline(file, strInput);
			cout << strInput << endl;
		}

		file >> colA;
		file >> colB;
		file >> colC;
		file >> colD;
		file >> colE;
		file >> colF;
		file >> colG;

		rain = rain + stoi(colF);

		if (counter == 12)
		{
			outputFile << colA << " " << rain << " " << endl;
			counter = 0;
			rain = 0;
		}
	}
}

void outputFile(string filename)
{

}

float calculateDD(float TJan, float TJul)
{
	// july average temperature
	//float TJul = (julMax + julMin) / 2;
	// jan average temperatures
	//float TJan = (janMax + janMin) / 2;

	//cout << "TJul = " << TJul << endl;
	//cout << "TJan = " << TJan << endl;

	float DEGD1 = (SINUS * (TJul - TJan));
	//cout << "DEGD1 = " << DEGD1 << endl;

	float DEGD2 = 182.5 * (5 - ((TJul + TJan) / 2));
	//cout << "DEGD2 = " << DEGD2 << endl;

	float DEGD3 = pow((5 - ((TJul + TJan) / 2)), 2);
	//cout << "DEGD3 = " << DEGD3 << endl;

	float DEGD4 = DEGD3 / (TJul - TJan);
	//cout << "DEGD4 = " << DEGD4 << endl;

	float DEGD5 = (SINUS * 2) * DEGD4;
	//cout << "DEGD5 = " << DEGD5 << endl;

	float DEGD6 = DEGD1 - DEGD2 + DEGD5;
	//cout << "DEGD6 = " << DEGD6 << endl;

	return DEGD6;
}

void outputDD(string filename, string outFile)
{
	ifstream file;
	file.open(filename);

	ofstream outputFile;
	outputFile.open(outFile);

	int smonth = 0;
	float janAvg1;
	float julAvg1;
	float DDays;

	string year, month, janMax, janMin, julMax, julMin, julAvg, janAvg;

	while (file)
	{
		smonth++;

		if (smonth == 1)
		{
			file >> year;
			file >> month;
			file >> janMin;
			file >> janMax;
			file >> janAvg;
			cout << "Avg Temp for January " << year << " = " << janAvg << endl;
			janAvg1 = strtof((janAvg).c_str(), 0);
		}

		if (smonth == 2)
		{
			file >> year;
			file >> month;
			file >> julMin;
			file >> julMax;
			file >> julAvg;
			cout << "Avg Temp for July " << year << " = " << julAvg << endl;
			julAvg1 = strtof((julAvg).c_str(), 0);
			cout << "DEGD for " << year << " = " << calculateDD(janAvg1, julAvg1) << endl;
			outputFile << year << ", " << calculateDD(janAvg1, julAvg1) << endl;
			smonth = 0;
		}
	}

	file.close();
	outputFile.close();
}

float getAverage(float a, float b)
{
	return (a + b) / 2;
}
