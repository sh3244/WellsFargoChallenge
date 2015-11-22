#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//Create constant variables for file names and key words
const string ORIGINAL = "dataset.txt";
const string BANKS[] = {"bankA.txt", "bankB.txt", "bankC.txt", "bankD.txt" };
const string WORKING_FILE = "workData.txt";
const string A = "BankA";
const string B = "BankB";
const string C = "BankC";
const string D = "BankD";

const int PIPES = 5;

//Remove the date in the data
//Leaves ID and text
//Writes the cleaned data in workData.txt
void cleanComments()
{
	ifstream dataset(ORIGINAL);
	ofstream file("workData.txt", ofstream::app);
	if (dataset && file)
	{
		string line;
		while (getline(dataset, line))
		{
			size_t index;
			for (unsigned i = 0; i < PIPES; i++)
			{
				index = line.find_first_of("|") + 1; 
				if (i == 0)
				{
					file << line.substr(0, index);
				}
				line = line.substr(index);
			}
			file << line << endl;
		}
		dataset.close();
		file.close();
	}
	else
	{
		cerr << "FILE NOT FOUND" << endl;
		system("pause");
	}
}

//Here the comments are sorted by the banks they refer to
//If the comment refers to multiple banks, they will be sorted into both files
void sortBank()
{
	ifstream dataset(WORKING_FILE);

	ofstream bankA(BANKS[0], ofstream::app);
	ofstream bankB(BANKS[1], ofstream::app);
	ofstream bankC(BANKS[2], ofstream::app);
	ofstream bankD(BANKS[3], ofstream::app);
	if (dataset)
	{
		string line;
		while (getline(dataset, line))
		{
			if (line.find(A) != string::npos)
			{
				bankA << line << endl;
			}
			if (line.find(B) != string::npos)
			{
				bankB << line << endl;
			}
			if (line.find(C) != string::npos)
			{
				bankC << line << endl;
			}
			if (line.find(D) != string::npos)
			{
				bankD << line << endl;
			}
		}
		bankA.close();
		bankB.close();
		bankC.close();
		bankD.close();
		dataset.close();
	}
	else
	{
		cerr << "FILE NOT FOUND" << endl;
		system("pause");
	}
}

int main()
{
	//cleanComments();
	//sortBank();
	system("pause");
}


