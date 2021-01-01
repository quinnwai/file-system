/*RemoveCommand.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class definition inheriting from AbstractCommand. Enables a user to remove files from the system.
*/

#pragma once
#include "RemoveCommand.h"
#include <iostream>

RemoveCommand::RemoveCommand(AbstractFileSystem* afs_) : afs(afs_) {}

int RemoveCommand::execute(std::string str) {
	return afs->deleteFile(str); // success/failure return values will be passed up
}

void RemoveCommand::displayInfo() {
	std::cout << "remove deletes a file with the provided name, can be called by the command: rm <filename>" << std::endl;
}