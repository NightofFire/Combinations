#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
using namespace std;

int main()
{
	Word word;
	Dictionary dic;
	dic.openFile();
	string userInput;
	vector<string> wordList;
	int index;
	int wordLength;
	long double counter;
	long double permCount;

	word.getUserInput();
	userInput = word.returnUserInput();
	word.sortString(userInput);
	wordList = word.returnWordList();
	index = word.returnIndex();
	wordLength = word.returnWordLength()-1;
	counter = word.returnCounter();
	word.getTotalPerm(word.returnUserInput());
	permCount = word.returnPermCount();
	word.generatePerm(userInput,wordList,index,wordLength,counter,permCount);
	word.sortList(wordList);
	word.deleteDuplicates(wordList);
	cout << endl;
	/*cout << userInput << endl;
	cout << index << endl;
	cout << wordLength << endl;
	cout << counter << endl;
	cout << permCount << endl;*/
	//wordList.erase(unique(wordList.begin(), wordList.end()), wordList.end());
	/*for (int i = 0; i < wordList.size(); i++)
	{
		cout << wordList[i] << endl;
	}*/
	dic.searchDic(wordList);
	return 0;
}
