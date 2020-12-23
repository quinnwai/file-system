/*AbstractFileSystem.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Declaration of the interface all file systems
*/

#pragma once
#include "AbstractFile.h"
#include <string>
#include <set>

class AbstractFileSystem {
public:
	virtual int addFile(std::string name, AbstractFile* file) = 0;
	virtual int deleteFile(std::string name) = 0;
	virtual AbstractFile* openFile(std::string name) = 0;
	virtual int closeFile(AbstractFile* file) = 0;
	//	have abstract file system destructor as virtual so that it looks for destructor in derived class (SimpleFileSystem)
	//	this is essential like dynamic look up so AbstractFileSystem has to find a corresponding implementation
	virtual ~AbstractFileSystem() = default;  
	// virtual std::set<std::string> getFileNames() = 0; // this needs to be completed
};