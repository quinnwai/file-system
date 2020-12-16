/*CatCommand.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a command that enables a user to append contents to a file
*/

#pragma once
#include "CatCommand.h"
#include "BasicDisplayVisitor.h"
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs_) : afs(afs_) {}

int CatCommand::execute(string str) {
	//NOTE: remember, str contains all parameters separated by space
	//extract from ss to see if first word can be opened
	istringstream iss(str);
	string firstWord;
	iss >> firstWord;
	
	AbstractFile* af = afs->openFile(firstWord); 

	//if not nullptr, then file does not exist. Else, look for second word
	if (!af) {
		cout << "no such file exists" << endl;
		return no_file_exists;
	}

	//extract again to see if an "-a" was used. If so, print the current contents of the file (bytes only?)
	string secondWord;
	iss >> secondWord;

	//if suffixed, print out contents
	bool isAppend = (secondWord == "-a");
	if (isAppend) {
		AbstractFileVisitor* afv = new BasicDisplayVisitor();
		af->accept(afv);
		delete afv;
	}

	//setup input into file and store all input in vector
	vector <char> allInput;
	string input;
	cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving" << endl;
	getline(cin, input);

	//create loop w/ three options to write or quit out: valid_text, ":wq", ":q"
	
	while (input != ":wq" && input != ":q") {
		for (char c : input) {
			allInput.push_back(c);
		}
		allInput.push_back('\n');

		cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving" << endl;
		getline(cin, input);
	}

	//if -a and input is :wq, append vec to file. If no -a and input is :wq, overwrite file

	int result = success;
	if (isAppend && input == ":wq") {
		allInput.erase(allInput.end()-1);
		result = af->append(allInput);
	}
	else if (!isAppend && input == ":wq") {
		allInput.erase(allInput.end() - 1);
		result = af->write(allInput);
	}
	
	afs->closeFile(af);
	return result;
}

void CatCommand::displayInfo(){
	cout << "cat adds information onto the file line by line" << endl;
	cout << "cat can be invoked with the command : cat <filename> [-a]" << endl;
	cout << "Use -a to append to the existing information in the file or leave out -a to overwrite all previous contents" << endl;
}