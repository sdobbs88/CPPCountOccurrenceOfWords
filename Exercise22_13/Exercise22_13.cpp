/**
* Class: CSCI2490 C++ Programming
* Instructor: Y. Daniel Liang
* Description: Counts occurrence of words in a file. File
* is determined from user providing a file path.
* Due: 12/05/2016
* @author Shaun C. Dobbs
* @version 1.0

* I pledge by honor that I have completed the programming assignment independently.
* I have not copied the code from a student or any source.
* I have not given my code to any student.

Sign here: Shaun C. Dobbs
*/

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <map>

// Correct filepath for test file:  F:\C++\test.txt

using namespace std;

int main()
{
	string path, word;
	map<string, int> map1;
	ifstream input;

	//Get file path from user
	cout << "Enter a file path: " << endl;
	getline(cin, path);

	input.open(path);

	while (input >> word) {
		try 
		{
			map1.at(word) += 1;
		}
		catch (const std::out_of_range& oor) 
		{
			map1[word] = 1;
		}
	}

	map<string, int>::iterator p;
	for (p = map1.begin(); p != map1.end(); p++)
		cout << p->first << " " << p->second << endl;

	input.close();
	return 0;
}

