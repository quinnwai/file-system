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
	iss >> copy_name;
	AbstractFile* original = afs->openFile(name);
	if (original == nullptr) {
		std::cout << "cannot open file" << std::endl;
		return no_file_exists;
	}
	if (copy_name == "") {
		std::cout << "invalid file name" << std::endl;
		return cannot_create_file;
	}
	//TODO: clone function of prototype pattern
	AbstractFile* copy = original->clone(copy_name);
	afs->closeFile(original);
	return afs->addFile(copy->getName(), copy);
	return success;
}

void CopyCommand::displayInfo() {
	std::cout << "copy copies a file and can be called with the command: cp <file_to_copy> <new_name_with_no_extension>" << std::endl;
}