#pragma once
#include "RenameParsingStrategy.h"
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string str) {
	//given an input string "<existing_file> <new_name>", the parse function will return a vector containing the strings
	//"<existing_file> <new_name>" and "<existing_file>" for teh copy and remove command respectively

	//declare strings and relevant streams
	std::string copyInput = "";
	std::string removeInput = "";
	std::string word;
	std::istringstream iss(str);

	//add first word to both 
	iss >> word;
	copyInput += word;
	removeInput += word;

	//add second word to both
	iss >> word;
	copyInput += word;

	//add strings to vector and return
	std::vector<std::string> vec;
	vec.push_back(copyInput);
	vec.push_back(removeInput);
	return vec;
}