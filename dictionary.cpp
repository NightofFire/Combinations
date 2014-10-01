/*******************************************************************************
Title          : dictionary.cpp
Author         : Cheng Pan
Created on     : September 29, 2014
Description    : Read input file, binary search.
Purpose        : To show how to do object oriented programming
Usage          : ./cp395_hwk1 open file.txt someword
Build with     : g++ -o cp395_hwk1 cp395_hwk1.cpp word.cpp word.h 
                 dictionary.cpp dictionary.h
Modifications  :
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "dictionary.h"
using namespace std;
/******************************************************************************/
/*                           Function Definitions                             */
/******************************************************************************/

/**
Word() A default constructor for the Word class
*/
Dictionary::Dictionary()
{}
/**
Word() A default constructor for the Word class
*/
Dictionary::~Dictionary()
{}
/**
	openFile(argc,argv)  open and read file from command line
*/
void Dictionary::openFile(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "To open a text file type: open <file name>" << endl;
	}
	string input, word; // user input, temp storage for dictionary word
	ifstream ifs;
	string firstWord, restWord; //open, file.txt
	int spaceLoc; //to store location where space occur
	if (argc > 1)
	{
		firstWord = argv[1];	//store command line arugment
		restWord = argv[2];		//store command line arugment
		transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::tolower);	//change firstWord to lower case
		ifs.open(restWord.c_str());		//open file.txt
		if (firstWord != "open" || ifs.fail()) {			//check if user entered "open" and if the file opens
			if (firstWord != "open" && !ifs.fail())			//if user entered "open" incorrectly
			{
				cerr << "ERROR : MISTYPED 'OPEN'" << endl;	//output error message
				return;
			}
			else if (ifs.fail() && firstWord == "open")		//if file didn't open
			{
				cerr << "ERROR : FILE NOT FOUND" << endl;	//output error message
				cerr << "FILENAMES ARE CASE SENSITIVE" << endl;
				return;
			}
			else											//if both are incorrect
			{
				cerr << "ERROR : MISTYPED 'OPEN' OR FILE NOT FOUND" << endl;
				cerr << "FILENAMES ARE CASE SENSITIVE" << endl;
				return;
			}
			//output usage
			cerr << "-- Note --" "\n";
			cerr << "Usage: open <file name>" "\n";
			cerr << "       exit " << endl;
			//clear and close istream file
			ifs.clear();
			ifs.close();
		}
	}
	//same as above except for a few lines
	//only used when running program without command line argument
	else
	{
		while (!ifs.is_open()) {					//loop until file is open
			getline(cin, input);					//get a line from user input. Example: "open text.txt"
			spaceLoc = input.find(' ');				//find where the space is
			firstWord = input.substr(0, spaceLoc);	//get substring from open to space, "open"
			transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::tolower);	//change firstWord to lower case
			restWord = input.substr(spaceLoc + 1);	//get rest of substring after space, "text.txt"
			ifs.open(restWord.c_str());				//open "file.txt"
			if (input == "exit") {					//if user enter "exit", program exits
				exit(0);
			}
			//same as above
			else if (firstWord != "open" || ifs.fail()) {
				if (firstWord != "open" && !ifs.fail())
				{
					cerr << "ERROR : MISTYPED 'OPEN'" << endl;
				}
				else if (ifs.fail() && firstWord == "open")
				{
					cerr << "ERROR : FILE NOT FOUND" << endl;
				}
				else
				{
					cerr << "ERROR : MISTYPED 'OPEN' OR FILE NOT FOUND" << endl;
				}
				cerr << "-- Note --" "\n";
				cerr << "Usage: open <file name>" "\n";
				cerr << "       exit " << endl;
				ifs.clear();
				ifs.close();
			}
		}
	}
	//display message if successfully opened file
	cout << "FILE OPENED SUCCESSFULLY" << endl;
	cout << "LOADING";

	//loop until all words in the file are stored in dicList vector
	while (!ifs.eof())
	{
		ifs >> word;
		dicList.push_back(word);
	}
	sort(dicList.begin(), dicList.end());	//sorts the vector in alphabetical order
	ifs.close();							//closes the ifstream file
}
/**
	searchDic(wordList)  search combinations in dictionary and display if found
*/
void Dictionary::searchDic(vector<string> &wordList)
{
	for (int i = 0; i<wordList.size(); i++)			//loop until i==size of vector
	{
		string input = wordList[i];					//current string to search
		int found = 0;
		int left = 0, right = dicList.size() - 1;
		while (found == 0)
		{
			if (left>right)							//exits loop
			{
				found = 1;
				//cout <<"NOT FOUND!"<<endl;
			}
			else
			{
				int middle = (left + right) / 2;	//sets the middle location
				if (dicList[middle] == input)		//if same string
				{
					// cout << wordList[middle]<<endl;
					found = 1;
					cout << "FOUND " << input << endl;
				}
				else if (dicList[middle]>input)		//if word is at the left side of vector
				{
					right = middle - 1;	
					// cout << wordList[middle]<<endl;
				}
				else if (dicList[middle]<input)		//if word is at the right side of vector
				{
					left = middle + 1;
					//cout << wordList[middle]<<endl;
				}
			}

		}
	}
}
/**
	newDic()  resets the values to default value if running the program without
*/
void Dictionary::newDic()
{
	dicList.erase(dicList.begin(), dicList.end());
	dicList.resize(0);
}