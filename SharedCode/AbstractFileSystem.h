#pragma once
#include "AbstractFile.h"
#include <string>
// declaration of the interface all file systems provide goes here

class AbstractFileSystem {
	
public:
	virtual int addFile(std::string name, AbstractFile* file) = 0;
//	virtual int createFile(std::string name) = 0;
	virtual int deleteFile(std::string name) = 0;
	virtual AbstractFile* openFile(std::string name) = 0;
	virtual int closeFile(AbstractFile* file) = 0;
	//FWL:	have abstract file system destructor as virtual so that it looks for destructor in derived class (SimpleFileSystem)
	//		this is essential like dynamic look up so AbstractFileSystem has to find a corresponding implementation
	virtual ~AbstractFileSystem() = default;  
};