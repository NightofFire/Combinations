#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <vector>
using namespace std;
class Word{
private:
	string userInput;
	vector<string> wordList;
	long double counter;
	long double permCount;
	int index;
	int wordLength;
public:
	Word();
	~Word();
	void getUserInput();
	string returnUserInput();
	vector<string> &returnWordList();
	int returnIndex();
	int returnWordLength();
	long double &returnCounter();
	long double returnPermCount();
	void generatePerm(string,vector<string>&,int,int,long double&,long double);
	void sortString(string);
	void getTotalPerm(string);
	void deleteDuplicates(vector<string>&);
	void sortList(vector<string>&);
};
#endif // WORD_H_
