#pragma once
#include "RenameParsingStrategy.h"
#include <sstream>
#include <iostream>

std::vector<std::string> RenameParsingStrategy::parse(std::string str) {
	//given an input string "<existing_file> <new_name>", the parse function will return a vector containing the strings
	//"<existing_file> <new_name>" and "<existing_file>" for the copy and remove commands respectively

	//declare strings and relevant streams
	std::string copyInput = "";
	std::string removeInput = "";
	std::string word;
	std::istringstream iss(str);

	//add first word to both 
	iss >> word;
	copyInput += word;
	removeInput += word;

	//add second word to copy
	iss >> word;
	copyInput += " " + word;

	//add strings to vector and return
	std::vector<std::string> vec;
	vec.push_back(copyInput);
	vec.push_back(removeInput);
	return vec;
}

void RenameParsingStrategy::displayInfo() {
	std::cout << "rn changes the name of a file" << std::endl;
	std::cout << "rn can be invoked with the command : rn <existing_file> <new_name_with_no_extension>" << std::endl;
}