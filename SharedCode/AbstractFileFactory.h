#pragma once
// studio 18 - file factory interface declared here
#include "AbstractFile.h"
#include <string>

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string name) = 0;
	virtual ~AbstractFileFactory() = default;
};
