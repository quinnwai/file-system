/*AbstractParsingStrategy.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Declaration of the interface for parsing strategies
*/

#pragma once
#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
	//separates an input string into a vector of strings, where each string correspond to each relevant command provided
	virtual std::vector<std::string> parse(std::string) = 0;

	//allowed display info to be specified for each implemented MacroCommand
	virtual void displayInfo() = 0;
};

