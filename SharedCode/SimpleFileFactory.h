#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFile.h"
#include <string>
#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
	AbstractFile* createFile(std::string name);
};
