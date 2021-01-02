/*SimpleFileFactory.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration of the SimpleFileFactory class, inherits from AbstractFileFactory
*/

#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFile.h"
#include <string>
#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
	AbstractFile* createFile(std::string name);
};
