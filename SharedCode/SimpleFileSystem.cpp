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
	if (files.find(name) != files.end()) return 1; // go back to enum this
	else if (file == nullptr) return 2; // same here
	files.insert({ name, file });
	return success;
}

int SimpleFileSystem::createFile(string name) {
	if (files.find(name) != files.end()) return 3; //
	int name_length = name.size();
	string ftype = "";
	ftype = ftype + name[name_length - 3] + name[name_length - 2] + name[name_length - 1];
	if (ftype == "txt") {
		AbstractFile* words = new TextFile(name);
		files.insert({ name, words });
		return success;
	}
	if (ftype == "img") {
		AbstractFile* pics = new ImageFile(name);
		files.insert({ name, pics });
		return success;
	}
}

int SimpleFileSystem::deleteFile(string name) { // ERROR HERE
	auto wantedFile = files.find(name);
	if (wantedFile == files.end()) return 6; // enum
	if (open_files.find(wantedFile->second) != open_files.end()) return 7; // enum
	delete files.at(name);
	files.erase(name);
	return success;

}

AbstractFile* SimpleFileSystem::openFile(string name) {
	auto wantedFile = files.find(name);
	if (wantedFile == files.end()) return nullptr; // enum error
	AbstractFile* thefile = wantedFile->second;
	if (open_files.find(thefile) != open_files.end()) return nullptr; // enum
	open_files.insert(thefile);
	return thefile;
 }

int SimpleFileSystem::closeFile(AbstractFile* file) {
	if (open_files.find(file) == open_files.end()) return 5; // enum
	open_files.erase(file);
	return success;
}

