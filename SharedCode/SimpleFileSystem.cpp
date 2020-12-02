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

SimpleFileSystem::SimpleFileSystem(AbstractFileFactory* f) : factory(f) {
	
}


SimpleFileSystem::~SimpleFileSystem() { //FWL: deletes all objects we created (so factory, but also abstractFile since inside map/set)
	delete factory;
	//TODO:	do sets and maps need to be destructed? I don't think so...
	//FWL:	https://isocpp.org/wiki/faq/dtors I found this which was helpful
}

int SimpleFileSystem::addFile(string name, AbstractFile* file) {
	if (files.find(name) != files.end()) return already_exists; 
	else if (file == nullptr) return invalid_file; 
	files.insert({ name, file });
	return success;
}

int SimpleFileSystem::deleteFile(string name) { // ERROR HERE
	auto wantedFile = files.find(name);
	if (wantedFile == files.end()) return no_file_exists; 
	if (open_files.find(wantedFile->second) != open_files.end()) return already_open; 
	delete files.at(name);
	files.erase(name);
	return success;

}

AbstractFile* SimpleFileSystem::openFile(string name) {
	auto wantedFile = files.find(name);
	if (wantedFile == files.end()) return nullptr; // enum error - file doesn't exist
	AbstractFile* thefile = wantedFile->second;
	if (open_files.find(thefile) != open_files.end()) return nullptr; // enum - file already open
	open_files.insert(thefile);
	return thefile;
 }

int SimpleFileSystem::closeFile(AbstractFile* file) {
	if (open_files.find(file) == open_files.end()) return unopened_file;
	open_files.erase(file);
	return success;
}

