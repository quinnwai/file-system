#pragma once
#include "MacroCommand.h"
#include <sstream>
#include <string>
#include <iostream>
#include "AbstractFile.h" //TODO: replace with enums when created

using namespace std;

//TODO: see if defined constructor is needed
//MacroCommand::MacroCommand() : aps(nullptr) {}

MacroCommand::MacroCommand(AbstractFileSystem* afs_) : afs(afs_) {}

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
}

//TODO: make sure it works for all things
void MacroCommand::displayInfo() {
	cout << "macro commands combine multiple existing commands into one single command" << endl;
	cout << "For most commands, put the relevant file name(s) first and then the relevant optional arguments" << endl;
}

void MacroCommand::addCommand(AbstractCommand* ac) {
	//TODO: why is the vector the actual commands instead of pointers
	//TODO: also make sure to see if void is fine
	this->vecCmds.push_back(ac);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps_) {
	aps = aps_;
}