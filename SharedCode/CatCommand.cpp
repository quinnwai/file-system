/*CatCommand.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a command that enables a user to append contents to a file
*/

#pragma once
#include "CatCommand.h"
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs_, AbstractFileFactory* aff_, AbstractFileVisitor* afv_) : afs(afs_), aff(aff_), afv(afv_) {}

int CatCommand::execute(string str) {
	//NOTE: remember, str contains all parameters separated by space
	//extract from ss to see if first word is a file inside the file system map member variable
	istringstream iss(str);
	string firstWord;
	iss >> firstWord;
	
	AbstractFile* af = aff->createFile(firstWord);  //use instead of friend to access friends

	//if not nullptr, then file did not exist before. Else, look for second word
	if (af) {
		afs->deleteFile(firstWord);
		cout << "no such file exists" << endl;
		return no_file_exists;
	}

	//extract again to see if an "-a" was used. If so, print the current contents of the file (bytes only?)
	string secondWord;
	iss >> secondWord;

	bool isAppend = (secondWord == "-a");
	if (isAppend) {
		af->accept(afv);
	}
	
	//setup input into file
	string input;
	getline(cin, input);

	//overwrite files before starting to append more data
	if (isAppend && input != ":wq" && input != ":q") {
		vector<char> vec = { '\n' };
		for (char c : input) {
			vec.push_back(c);
		}

		af->write(vec);
		getline(cin, input);
	}

	//create loop w/ three options to write or quit out: valid_text, ":wq", ":q"
	while (input != ":wq" && input != ":q") {
		cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving" << endl;
		vector<char> vec = {'\n'};
		for (char c : input) {
			vec.push_back(c);
		}

		af->append(vec);
		getline(cin, input);
	}
	return success;
}

void CatCommand::displayInfo(){
	cout << "cat adds information onto the file line by line, cat can be invoked with the command : cat <filename> [-a]"
		<< ", use -a to append to the existing information in the file and leave out -a to overwrite all previous contents" << endl;
}