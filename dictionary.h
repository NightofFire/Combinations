#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dictionary{
private:
	vector<string> dicList;
public:
	Dictionary();
	~Dictionary();
	void openFile();
	void searchDic(vector<string>&);
};
#endif // DICTIONARY_H_