/*SimpleFileSystem.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a simple file system which is used to store files
*/

#pragma once

#include "SimpleFileSystem.h"
#include <string>
#include <map>
#include <set>
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"

int SimpleFileSystem::addFile(std::string name, AbstractFile* file) {
	if (files.find(name) != files.end()) return file_already_exists; 
	else if (file == nullptr) return invalid_file; 
	files.insert({ name, file });
	return success;
}

int SimpleFileSystem::deleteFile(std::string name) {
	auto wantedFile = files.find(name);
	if (wantedFile == files.end()) return no_file_exists; 
	if (open_files.find(wantedFile->second) != open_files.end()) return file_already_open; 
	delete files.at(name);
	files.erase(name);
	return success;
}

AbstractFile* SimpleFileSystem::openFile(std::string name) {
	auto wantedFile = files.find(name);
	if (wantedFile == files.end()) return nullptr; //file does not exist
	AbstractFile* thefile = wantedFile->second;
	if (open_files.find(thefile) != open_files.end()) return nullptr; //file already open
	open_files.insert(thefile);
	return thefile;
 }

int SimpleFileSystem::closeFile(AbstractFile* file) {
	if (open_files.find(file) == open_files.end()) return unopened_file;
	open_files.erase(file);
	return success;
}

std::set<std::string> SimpleFileSystem::getFileNames() { // returns a list of all the file names in the system
	std::set<std::string> file_names;
	std::map<std::string, AbstractFile*>::iterator iter;
	for (iter = files.begin(); iter != files.end(); ++iter) { // inserts files in the system into a set
		file_names.insert(iter->first);
	}
	return file_names;
}

