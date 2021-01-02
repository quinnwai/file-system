/*AbstractFileFactory.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Declaration of a file factory interface which is responsible for the creation of files.
*/

#pragma once
// studio 18 - file factory interface declared here
#include "AbstractFile.h"
#include <string>

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string name) = 0;
	//virtual ~AbstractFileFactory() = default;
};
