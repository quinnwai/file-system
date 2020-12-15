// define methods of SimpleFileSystem class here
#pragma once

#include "SimpleFileSystem.h"
#include <string>
#include <map>
#include <set>
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;

int SimpleFileSystem::addFile(string name, AbstractFile* file) {
	if (files.find(name) != files.end()) return file_already_exists; 
	else if (file == nullptr) return invalid_file; 
	files.insert({ name, file });
	return success;
}

int SimpleFileSystem::deleteFile(string name) { 
	auto wantedFile = files.find(name);
	if (wantedFile == files.end()) return no_file_exists; 
	if (open_files.find(wantedFile->second) != open_files.end()) return file_already_open; 
	delete files.at(name);
	files.erase(name);
	return success;

}

AbstractFile* SimpleFileSystem::openFile(string name) {
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

