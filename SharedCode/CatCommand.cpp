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

CatCommand::CatCommand(AbstractFileSystem* afs_) : afs(afs_) {}

int CatCommand::execute(std::string str) {
	//NOTE: remember, str contains all parameters separated by space
	//extract from ss to see if first word can be opened
	std::istringstream iss(str);
	std::string firstWord;
	iss >> firstWord;
	
	AbstractFile* af = afs->openFile(firstWord); 

	//if not nullptr, then file does not exist. Else, look for second word
	if (!af) {
		std::cout << "no such file exists" << std::endl;
		return no_file_exists;
	}

	//extract again to see if an "-a" was used. If so, print the current contents of the file (bytes only?)
	std::string secondWord;
	iss >> secondWord;

	//if suffixed, print out contents as bytes (ie unformatted)
	bool isAppend = (secondWord == "-a");
	if (isAppend) {
		std::vector<char> vec = af->read();
		for (char c : vec) {
			std::cout << c;
		}
		std::cout << std::endl;

		/*AbstractFileVisitor* afv = new BasicDisplayVisitor();
		af->accept(afv);
		delete afv;*/
	}

	//setup input into file and store all input in vector
	std::vector <char> allInput;
	std::string input;
	std::cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving" << std::endl;
	getline(std::cin, input);

	//create loop w/ three options to write or quit out: valid_text, ":wq", ":q"
	while (input != ":wq" && input != ":q") {
		for (char c : input) {
			allInput.push_back(c);
		}
		allInput.push_back('\n');

		std::cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit. Enter :q to exit without saving" << std::endl;
		getline(std::cin, input);
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
	std::cout << "cat adds information onto the file line by line" << std::endl;
	std::cout << "cat can be invoked with the command : cat <filename> [-a]" << std::endl;
	std::cout << "Use -a to append to the existing information in the file or leave out -a to overwrite all previous contents" << std::endl;
}