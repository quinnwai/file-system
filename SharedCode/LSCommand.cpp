#pragma once
#include "LSCommand.h"
#include <iostream>

LSCommand::LSCommand(AbstractFileSystem* afs1) : afs(afs1) {}

void LSCommand::displayInfo() {
	std::cout << "ls lists the names of all the files in the file system, it can be called by the command : ls" << std::endl;
	std::cout << "to display the metadata of all the files in the file system, call the command : ls -m" << std::endl;
}

int LSCommand::execute(std::string str) { // need to finish
	return success;
}