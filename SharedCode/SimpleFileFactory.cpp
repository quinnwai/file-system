// studio 18 - simple file factory definitions
#pragma once

#include "AbstractFile.h"
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <string>
using namespace std;

AbstractFile* SimpleFileFactory::createFile(string name) {
	string ftype = "";
	if (name.length() <= 3) {
		return nullptr;
	}
	ftype = ftype + name[name.length() - 3] + name[name.length() - 2] + name[name.length() - 1];
	if (ftype == "txt") {
		AbstractFile* words = new TextFile(name);
		return words;
	}
	if (ftype == "img") {
		AbstractFile* pics = new ImageFile(name);
		return pics;
	}
	else {
		return nullptr;
	}
}

