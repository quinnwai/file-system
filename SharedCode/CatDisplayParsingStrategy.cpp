#pragma once
#include "CatDisplayParsingStrategy.h"
#include <sstream>
#include <iostream>

std::vector<std::string> CatDisplayParsingStrategy::parse(std::string str) {
	//given an input string "<file_name> [-a] [-d]", the parse function will return a vector containing the strings
	//"<file_name> [-a]" and "<file_name> [-d]" for the cat and display commands respectively

	//declare strings and relevant streams
	std::string catInput = "";
	std::string dsInput = "";
	std::string word;
	std::istringstream iss(str);

	//add first word to both (file name)
	iss >> word;
	catInput += word;
	dsInput += word;

	//check if second word exists and add necessarily
	if (iss >> word) {
		//first word is for cat [-a], then check for next argument for display [-d]
		if (word == "-a") {
			catInput += " " + word;
			if (iss >> word && word == "-d") {
				dsInput += " " + word;
			}
		}
		//first word is for display [-d], then check for next argument for cat [-a]
		else {
			dsInput += " " + word;
			if (iss >> word && word == "-a") {
				catInput += " " + word;
			}
		}
	}

	//add strings to vector and return
	std::vector<std::string> vec;
	vec.push_back(catInput);
	vec.push_back(dsInput);
	return vec;
}

void CatDisplayParsingStrategy::displayInfo() {
	std::cout << "cds combines cat and ds to change file contents and display those contents afterwards" << std::endl;
	std::cout << "cds can be invoked with the command : cds <file_name> [-a] [-d]" << std::endl;
	std::cout << "Use -a to append to the existing information in the file or leave out -a to overwrite all previous contents" << std::endl;
	std::cout << "Use -d to show a unformatted version or leave out -d to show a formatted version" << std::endl;
}