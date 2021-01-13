/*CopyCommand.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class definition inheriting from AbstractCommand. Enables a user to copy/duplicate files in the system with a new name.
*/

#pragma once
#include "CopyCommand.h"
#include <iostream>
#include <sstream>

CopyCommand::CopyCommand(AbstractFileSystem* afs_) : afs(afs_) {}

int CopyCommand::execute(std::string str) {
	std::string name;
	std::string copy_name;
	std::istringstream iss(str);
	iss >> name;
	iss >> copy_name; // by now, file name and copy name will be properly assigned
	AbstractFile* original = afs->openFile(name); // access file being copied, following ifs ensure copying can be properly completed
	if (original == nullptr) {
		std::cout << "cannot open file" << std::endl;
		delete original;
		return no_file_exists;
	}
	if (copy_name == "") {
		std::cout << "invalid file name" << std::endl;
		delete original;
		return cannot_create_file;
	}
	AbstractFile* copy = original->clone(copy_name); // carry out prototype pattern (clone is defined by individual file types)
	afs->closeFile(original);
	return afs->addFile(copy->getName(), copy);
}

void CopyCommand::displayInfo() {
	std::cout << "copy copies a file and can be called with the command: cp <file_to_copy> <new_name_with_no_extension>" << std::endl;
}