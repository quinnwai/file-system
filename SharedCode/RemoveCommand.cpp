#pragma once
#include "RemoveCommand.h"
#include <iostream>

RemoveCommand::RemoveCommand(AbstractFileSystem* afs_) : afs(afs_) {}

int RemoveCommand::execute(std::string str) {
	//TODO: temporary for build of rename command
	return afs->deleteFile(str);
}

void RemoveCommand::displayInfo() {
	std::cout << "remove deletes a file with the provided name, can be called by the command: rm <filename>" << std::endl;
}