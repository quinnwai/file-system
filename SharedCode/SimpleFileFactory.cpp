/*SimpleFileFactory.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a simple file factory which is used to create files
*/

#pragma once
#include "AbstractFile.h"
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <string>

AbstractFile* SimpleFileFactory::createFile(std::string name) {
	std::string ftype = "";
	if (name.length() <= 4) {
		return nullptr;
	}
	ftype = ftype + name[name.length() - 4] + name[name.length() - 3] + name[name.length() - 2] + name[name.length() - 1];
	if (ftype == ".txt") {
		AbstractFile* words = new TextFile(name);
		return words;
	}
	else if (ftype == ".img") {
		AbstractFile* pics = new ImageFile(name);
		return pics;
	}
	else {
		return nullptr;
	}
}

