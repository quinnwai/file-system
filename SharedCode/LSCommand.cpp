#pragma once
#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
#include <iostream>

LSCommand::LSCommand(AbstractFileSystem* afs1) : afs(afs1) {}

void LSCommand::displayInfo() {
	std::cout << "ls lists the names of all the files in the file system, it can be called by the command : ls" << std::endl;
	std::cout << "to display the metadata of all the files in the file system, call the command : ls -m" << std::endl;
}

int LSCommand::execute(std::string str) { // need to finish
	if (str == "-m") {
		std::set<std::string> files = afs->getFileNames();
		std::set<std::string>::iterator iter;
		for (iter = files.begin(); iter != files.end(); ++iter) {
			AbstractFileVisitor* mdv = new MetadataDisplayVisitor;
			AbstractFile* current = afs->openFile(*iter);
			current->accept(mdv);
			afs->closeFile(current);
		}
	}
	else {
		std::set<std::string> files = afs->getFileNames();
		std::set<std::string>::iterator iter;
		int longest = 0;
		for (std::string name : files) {
			if (name.size() > longest) {
				longest = name.size();
			}

		}
		int i = 0;
		for (iter = files.begin(); iter != files.end(); ++iter) {
			std::cout << *iter;
			for (int i = 0; i < 10 + longest - (*iter).size(); ++i) {
				std::cout << ' ';
			}

			if (i % 2 == 1) {
				std::cout << std::endl;
			}
			++i;
		}
		std::cout << std::endl;
	}
	return success;
}