/*MacroCommand.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Implementation of a "macrocommand" which will allow the creation of commands out of other commands
*/

#pragma once
#include "MacroCommand.h"
#include <sstream>
#include <string>
#include <iostream>
#include "Enums.h"

MacroCommand::MacroCommand(AbstractFileSystem* afs_) : afs(afs_) {}

int MacroCommand::execute(std::string str)  {
	//use AbstractParsingStrategy to parse and create vector
	std::vector<std::string> vecInputs = aps->parse(str);

	//use first word of each input to create a command for it and store in vecCmds
	for (int i = 0; i < vecInputs.size(); ++i) {
		int result = (*vecCmds[i]).execute(vecInputs[i]);
		if (result != success) {
			return result;
		}
	}
	return success;
}

void MacroCommand::displayInfo() {
	aps->displayInfo();
}

void MacroCommand::addCommand(AbstractCommand* ac) {
	this->vecCmds.push_back(ac);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps_) {
	aps = aps_;
}