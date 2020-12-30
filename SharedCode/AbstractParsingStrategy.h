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

