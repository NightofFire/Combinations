/*****************************************************************************************************************************
Title          : cp395_hwk1.cpp
Author         : Cheng Pan
Created on     : September 29, 2014
Description    : Header file for word.cpp
Purpose        : object oriented programming.
Usage          : ./cp395_hwk1 open file.txt someword
Build with     : g++ -o cp395_hwk1 cp395_hwk1.cpp word.cpp word.h dictionary.cpp dictionary.h
Modifications  :
******************************************************************************************************************************/

#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <vector>
using namespace std;
class Word{
private:
	string userInput;			//word from user input
	vector<string> wordList;	//vector list to store all the combinations of word
	long double counter;		//counter for permutation count
	long double permCount;		//total number of permutation of word
	int index;					//starting point
	int wordLength;				//length of word
public:
	/******************************************************************************/
	/*                           Function Prototypes                              */
	/******************************************************************************/

	/** Word() A default constructor for the Word class
	*   Sets counter, permCount, index, and wordLength to 0.
	*/
	Word();
	~Word();//default destructor
	/**
	*  returnUserInput()  return user input
	*  @return   string
	*/
	void getUserInput(int, char*[]);
	/**
	*  getUserInput(argc,argv)  get user input;
	*  @param    int	argc	[in]	number of command line arguments
	*  @param    char	*argv[] [in]	command line arguments
	*  @post     if there are more than 1 argument, userInput=argv[3]
				 if less than 2 argument, userInput= user input
	*  @return   void
	*/
	string returnUserInput();
	/**
	*  returnWordList()  return vector
	*  @return   vector<string>
	*/
	vector<string> &returnWordList();
	/**
	*  returnIndex()  return index
	*  @return   int
	*/
	int returnIndex();
	/**
	*  returnWordLength()  return length of word
	*  @return   int
	*/
	int returnWordLength();
	/**
	*  returnCounter()  return permutation count
	*  @return   long double
	*/
	long double &returnCounter();
	/**
	*  returnPermCount()  return total permutation count
	*  @return   long double
	*/
	long double returnPermCount();
	/**
	*  generatePerm(word,wordList,index,wordLength,counter,permCount)  generate all combinations for word
	*  @param    string			word		[in]		string from userInput
	*  @param    vector<string>	&wordList	[in/out]	list of combination of word
	*  @param    index			index		[in]		starts from 0
	*  @param    int			wordLength	[in]		length of word
	*  @param    long double	&counter	[in/out]	permutation counter
	*  @param    long doubler	permCount	[in]		total permutation counter
	*  @post     store all the possible combinations of word in wordList
	*  @return   void
	*/
	void generatePerm(string,vector<string>&,int,int,long double&,long double);
	/**
	*  sortString(input)  sort the string in alphabetical order
	*  @param    string		input	[in/out]	string from userInput
	*  @return   void
	*/
	void sortString(string);
	/**
	*  getTotalPerm()  get total number of permutation of the string
	*  @param    string		input	[in/out]	a string
	*  @return   void
	*/
	void getTotalPerm(string);
	/**
	*  deleteDuplicates(List)  delete duplicates adjacent to each other
	*  @param    vector<string>		&List	[in/out]	vector list
	*  @pre		 needs to be sorted in alphabetical order
	*  @return   void
	*/
	void deleteDuplicates(vector<string>&);
	/**
	*  sortList(List)  sort the string in alphabetical order
	*  @param    vector<string>		&List	[in/out]	vector list to be sorted
	*  @return   void
	*/
	void sortList(vector<string>&);
	/**
	*  resetValues()  resets the values to default value if running the program without command line arguments because of loop
	*  @return   void
	*/
	void resetValues();
};
#endif // WORD_H_
