/*******************************************************************************
Title          : cp395_hwk1.cpp
Author         : Cheng Pan
Created on     : September 29, 2014
Description    : Header file for dictionary.cpp
Purpose        : To show how to do object oriented programming. 
Usage          : ./cp395_hwk1 open file.txt someword
Build with     : g++ -o cp395_hwk1 cp395_hwk1.cpp word.cpp word.h 
				 dictionary.cpp dictionary.h
Modifications  :
*******************************************************************************/

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dictionary{
private:
	vector<string> dicList;//vector list to store dictionary words
public:
	/******************************************************************************/
	/*                           Function Prototypes                              */
	/******************************************************************************/
	Dictionary(); //default constructor
	~Dictionary();	//default destructor
	/**
	*  openFile(argc,argv)  open and read file from command line
	*  @param    int	argc	[in]	number of command line arguments
	*  @param    char	*argv[] [in]	command line arguments
	*  @return   void
	*/
	void openFile(int, char*[]);
	/**
	*  searchDic(wordList)  search combinations in dictionary and display if found
	*  @param    vector<string>	&wordList	[in/]   vector list of words
	*  @return   void
	*/
	void searchDic(vector<string>&);
	/**
	*  newDic()  resets the values to default value if running the program without 
				 command line arguments when opening another file
	*  @return   void
	*/
	void newDic();
};
#endif // DICTIONARY_H_