#pragma once
#include "MacroCommand.h"
#include <sstream>
#include <string>
#include "AbstractFile.h" //TODO: replace with enums when created

using namespace std;

//TODO: see if defined constructor is needed
//MacroCommand::MacroCommand() : aps(nullptr) {}

int MacroCommand::execute(string str)  {
	//use AbstractParsingStrategy to parse and create vector
	vector<string> vecInputs = aps->parse(str);

	//use first word of each input to create a command for it and store in vecCmds
	for (int i = 0; i < vecInputs.size(); ++i) {
		//TODO: make sure these are corresponding properly
		int result = (*vecCmds[i]).execute(vecInputs[i]);
		if (result != success) {
			return result;
		}
	}
	return success;

	//string input;
	//string word;

	////read in first word. If it is a command, continue running. If not, return no_command_found 
	//istringstream iss(str);
	//iss >> word;

	//if()
	//input +=

	////while there are things to extract, if the word 
	//while (iss >> word) { //TODO: might cause issues if one thing only
	//	if
	//}

}
void MacroCommand::displayInfo() {

}

void MacroCommand::addCommand(AbstractCommand* ac) {
	//TODO: why is the vector the actual commands instead of pointers
	//TODO: also make sure to see if void is fine
	this->vecCmds.push_back(ac);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps_) {
	aps = aps_;
}