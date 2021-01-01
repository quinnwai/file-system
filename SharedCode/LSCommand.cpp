/*LSCommand.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class definition inheriting from AbstractCommand. Enables a user to display file names and metadata in the system.
*/

#pragma once
#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
#include <iostream>

LSCommand::LSCommand(AbstractFileSystem* afs1) : afs(afs1) {}

void LSCommand::displayInfo() {
	std::cout << "ls lists the names of all the files in the file system, it can be called by the command : ls" << std::endl;
	std::cout << "to display the metadata of all the files in the file system, call the command : ls -m" << std::endl;
}

int LSCommand::execute(std::string str) {
	if (str == "-m") { // will print out metadata of all files
		std::set<std::string> files = afs->getFileNames();
		std::set<std::string>::iterator iter;
		for (iter = files.begin(); iter != files.end(); ++iter) { // loop goes over the files and uses a visitor pattern to display each file's metadata
			AbstractFileVisitor* mdv = new MetadataDisplayVisitor;
			AbstractFile* current = afs->openFile(*iter);
			current->accept(mdv);
			afs->closeFile(current);
		}
	}
	else { // no metadata, just file names
		std::set<std::string> files = afs->getFileNames();
		std::set<std::string>::iterator iter;
		int i = 0;
		for (iter = files.begin(); iter != files.end(); ++iter) {
			std::cout << *iter;
			for (int j = 0; j < 20 - (*iter).size(); ++j) { // establishes consistent spacing between file names (max length of 20 is assumed per instructions)
				std::cout << ' ';
			}

			if (i % 2 == 1) { // prints only two file names per line
				std::cout << std::endl;
			}
			++i;
		}
		std::cout << std::endl;
	}
	return success;
}