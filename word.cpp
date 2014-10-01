/*******************************************************************************
Title          : cp395_hwk1.cpp
Author         : Cheng Pan
Created on     : September 29, 2014
Description    : Get user input, get all combinations, sort string, 
				 delete duplicates, sort vecotrs, and counters
Purpose        : object oriented programming.
Usage          : ./cp395_hwk1 open file.txt someword
Build with     : g++ -o cp395_hwk1 cp395_hwk1.cpp word.cpp word.h 
				 dictionary.cpp dictionary.h
Modifications  :
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "word.h"
using namespace std;

/******************************************************************************/
/*                           Function Definitions                             */
/******************************************************************************/

/** 
	Word() A default constructor for the Word class
*/
Word::Word()
{
	counter = 0;
	permCount = 0;
	index = 0;
	wordLength = 0;
}
/**
	~Word() A default destructor for the Word class
*/
Word::~Word()
{
}
/**
	returnUserInput()  return user input
*/
string Word::returnUserInput()
{
	return userInput;
}
/**
	getUserInput(argc,argv)  get user input;
*/
void Word::getUserInput(int argc, char *argv[])
{
	cout << "\r" << "Enter a word to search" << flush; //replace "loading" message
	cout << endl;
	if (argc < 2)	//if running program without command line argument
	{
		while (true)
		{
			cin >> userInput;
			if (userInput.length() >= 2 && userInput.length() <= 32)
			{
				break;
			}
			cerr << "ERROR : PLEASE A STRING OF AT LEAST 2 AND AT MOST 32 CHARACTERS." << endl;
		}
		
	}
	else			//if running program with command line argument
	{
		userInput = argv[3];
		if (userInput.length() >= 2 && userInput.length() <= 32)
		{

		}
		else
		{
			cerr << "ERROR : PLEASE A STRING OF AT LEAST 2 AND AT MOST 32 CHARACTERS." << endl;
			exit(0);
		}
	}
}
/**
	returnWordList()  return vector
*/
vector<string> &Word::returnWordList()
{
	return wordList;
}
/**
	returnIndex()  return index
*/
int Word::returnIndex()
{
	return index;
}
/**
	returnWordLength()  return length of word
*/
int Word::returnWordLength()
{
	wordLength = userInput.length();
	return wordLength;
}
/**
	returnCounter()  return permutation count
*/
long double &Word::returnCounter()
{
	return counter;
}
/**
	returnPermCount()  return total permutation count
*/
long double Word::returnPermCount()
{
	return permCount;
}
/**
	generatePerm(word,wordList,index,wordLength,counter,permCount)  generate all combinations for word
*/
void Word::generatePerm(string word, vector<string> &wordList, int index, int wordLength, long double &counter, long double permCount)
{
	if (counter == permCount)	//finish when current permutation counter==total permutation counter
	{
		return;
	}
	else
	{
		if (index == wordLength)	//Enter if it chosen all the possible characters
		{
			for (int i = 0; i<word.length() - 1; i++)	//double foor loop to get all the substrings of current permutation
			{
				for (int l = 1; l<word.length() - i + 1; l++)
				{
					wordList.push_back(word.substr(i, l));	//store all possible substrings in a vector
				}
			}
			counter++;	//permutation counter increases by 1 each time
			cout << "\r" << fixed << setprecision(2) << counter / permCount * 100 << "% " << flush;	//shows the progress
		}
		else
		{
			for (int j = index; j <= wordLength; j++)
			{
				//switch the element at the 2 location with eachother
				char temp[1];
				temp[0] = word[index];
				word[index] = word[j];
				word[j] = temp[0];
				generatePerm(word, wordList, index + 1, wordLength, counter, permCount);	//get the remaining letters
				//undo the previous switch
				temp[0] = word[index];
				word[index] = word[j];
				word[j] = temp[0];
			}
		}
	}
}
/**
	sortString(input)  sort the string in alphabetical order
*/
void Word::sortString(string input)
{
	sort(input.begin(), input.end());
}
/**
	deleteDuplicates(List)  delete duplicates adjacent to each other
*/
void Word::deleteDuplicates(vector<string> &List)
{
	List.erase(unique(List.begin(), List.end()), List.end());	//need to sort first
}
/**
	getTotalPerm()  get total number of permutation of the string
*/
void Word::getTotalPerm(string input)
{
	int counter = 0;
	do {
		counter++;
	} while (next_permutation(input.begin(), input.end()));
	permCount = counter;
}
/**
	sortList(List)  sort the string in alphabetical order
*/
void Word::sortList(vector<string> &List)
{
	sort(List.begin(), List.end());
}
/**
	resetValues()  resets the values to default value if running the program without command line arguments because of loop
*/
void Word::resetValues()
{
	counter = 0;
	permCount = 0;
	index = 0;
	wordLength = 0;
	wordList.erase(wordList.begin(), wordList.end());
	wordList.resize(0);
}