#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "word.h"
using namespace std;

Word::Word()
{
	counter = 0;
	permCount = 0;
	index = 0;
	wordLength = 0;
}
Word::~Word()
{

}
string Word::returnUserInput()
{
	return userInput;
}
void Word::getUserInput()
{
	cout << "Enter a word to search" << endl;
	cin >> userInput;
}
vector<string> &Word::returnWordList()
{
	return wordList;
}
int Word::returnIndex()
{
	return index;
}
int Word::returnWordLength()
{
	wordLength = userInput.length();
	return wordLength;
}
long double &Word::returnCounter()
{
	return counter;
}
long double Word::returnPermCount()
{
	return permCount;
}
void Word::generatePerm(string word, vector<string> &wordList, int index, int wordLength, long double &counter, long double permCount)
{
	if (counter >= permCount)
	{
		return;
	}
	else
	{
		if (index == wordLength)
		{
			for (int i = 0; i<word.length() - 1; i++)
			{
				for (int l = 1; l<word.length() - i + 1; l++)
				{
					wordList.push_back(word.substr(i, l));
				}
			}
			counter++;
			cout << "\r" << fixed << setprecision(2) << counter / permCount * 100 << "% " << flush;
		}
		else
		{
			for (int j = index; j <= wordLength; j++)
			{
				char temp[1];
				temp[0] = word[index];
				word[index] = word[j];
				word[j] = temp[0];
				//swap(word[index], word[j]);
				generatePerm(word, wordList, index + 1, wordLength, counter, permCount);
				temp[0] = word[index];
				word[index] = word[j];
				word[j] = temp[0];
				swap(word[index], word[j]);
			}
		}
	}
}

void Word::sortString(string input)
{
	sort(input.begin(), input.end());
}
void Word::deleteDuplicates(vector<string> &List)
{
	List.erase(unique(List.begin(), List.end()), List.end());
}
void Word::getTotalPerm(string input)
{
	int counter = 0;
	do {
		counter++;
	} while (next_permutation(input.begin(), input.end()));
	permCount = counter;
}
void Word::sortList(vector<string> &List)
{
	sort(List.begin(), List.end());
}