/*******************************************************************************
Title          : cp395_hwk1.cpp
Author         : Cheng Pan
Created on     : September 29, 2014
Description    : The objective of the program, having been given a word, is to 
				 find all words of that are combinations of the letters in the 
				 original word, and that are in the dictionary. 
Purpose        : Practice with recursion
Usage          : ./cp395_hwk1 open file.txt someword
Build with     : g++ -o cp395_hwk1 cp395_hwk1.cpp word.cpp word.h 
				 dictionary.cpp dictionary.h
Modifications  :
*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 4 && argc > 1)
	{
		cerr << "Usage: " << argv[0] << " OPEN FILE.TXT WORD" << endl;
		return 1;
	}
	Word word;
	Dictionary dic;
	string command;
	dic.openFile(argc, argv);
	while (command != "exit")
	{
		bool loop = true;
		string userInput;
		vector<string> wordList;
		int index;
		int wordLength;
		long double counter;
		long double permCount;

		word.getUserInput(argc, argv);				//get string from user input
		userInput = word.returnUserInput();			//store string in userInput
		word.sortString(userInput);					//sort string
		wordList = word.returnWordList();			//store wordList vector in local wordList
		index = word.returnIndex();					//store index in local index
		wordLength = word.returnWordLength() - 1;	//store word length in local wordLength
		counter = word.returnCounter();				//store counter in local counter
		word.getTotalPerm(word.returnUserInput());	//get total permutation of word
		permCount = word.returnPermCount();			//store total permutation of word in permCount
		word.generatePerm(userInput, wordList, index, wordLength, counter, permCount);	//generate all possible combinations of word
		word.sortList(wordList);					//sort the vector
		word.deleteDuplicates(wordList);			//delete duplicates
		cout << endl;
		dic.searchDic(wordList);					//search the dictionary for words

		if (argc < 2)	//keep running only when running program without command line argument
		{
			cout << "To search another word, enter: 'search'. To open a new dictionary, enter: 'new'. To exit the program, enter : 'exit'" << endl;
			cin >> command;
			while (loop == true)
			{
				if (command == "search")
				{
					word.resetValues();
					loop = false;
				}
				else if (command == "new")
				{
					dic.newDic();
					cin.ignore(256, '\n');
					dic.openFile(argc, argv);
					word.resetValues();
					loop = false;
				}
				else if (command == "exit")
				{
					exit(0);
				}
				else
				{
					cerr << "ERROR : COMMAND NOT FOUND." << endl;
					cerr << "To search another word, enter: 'search'. To open a new dictionary, enter: 'new'.To exit the program, enter : 'exit'" << endl;
					cin >> command;
				}
			}
		}
		else
		{
			command = "exit";
		}
		
	}
	return 0;
}
