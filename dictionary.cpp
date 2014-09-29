#include <iostream>
#include <fstream>
#include <algorithm>
#include "dictionary.h"
using namespace std;

Dictionary::Dictionary()
{}
Dictionary::~Dictionary()
{}
void Dictionary::openFile()
{
	cout << "To open a text file type: open <file name>" << endl;
	string input, line,word;
	ifstream ifs;
	string firstWord, restWord;
	int spaceLoc;
	while (!ifs.is_open()) {
		getline(cin, input);
		spaceLoc = input.find(' ');
		firstWord = input.substr(0, spaceLoc);
		transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::tolower);
		restWord = input.substr(spaceLoc + 1);
		ifs.open(restWord);
		if (input == "exit") {
			exit(0);
		}
		else if (firstWord != "open" || ifs.fail()) {
			if (firstWord != "open" && !ifs.fail())
			{
				cerr << "ERROR : MISTYPED 'OPEN'" << endl;
			}
			else if (ifs.fail() && firstWord=="open")
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
			ifs.close();
			ifs.clear();
		}
	}
	cout << "FILE OPENED SUCCESSFULLY" << endl;
	while (!ifs.eof())
	{
		ifs >> word;
		dicList.push_back(word);
	}
	sort(dicList.begin(), dicList.end());
	ifs.close();
	ifs.clear();
}
void Dictionary::searchDic(vector<string> &wordList)
{
	for (int i = 0; i<wordList.size(); i++)
	{
		string input = wordList[i];
		int found = 0;
		int left = 0, right = dicList.size() - 1;
		while (found == 0)
		{
			if (left>right)
			{
				found = 1;
				//cout <<"NOT FOUND!"<<endl;
			}
			else
			{
				int middle = (left + right) / 2;
				if (dicList[middle] == input)
				{
					// cout << wordList[middle]<<endl;
					found = 1;
					cout << "FOUND " << input << endl;
				}
				else if (dicList[middle]>input)
				{
					right = middle - 1;
					// cout << wordList[middle]<<endl;
				}
				else if (dicList[middle]<input)
				{
					left = middle + 1;
					//cout << wordList[middle]<<endl;
				}
			}

		}
	}
}