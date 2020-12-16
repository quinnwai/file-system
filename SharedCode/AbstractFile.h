#pragma once
#include "Enums.h"
#include<vector>
#include<string>


// declare AbstractFileVisitor here. As all methods are virtual and will not be defined, no .cpp file is necessary
class AbstractFileVisitor;

class AbstractFile {
public:
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char> vec) = 0;
	virtual int append(std::vector<char> vec) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual void accept(AbstractFileVisitor*) = 0; //calls on correct visitor pattern method for concrete file type
	virtual ~AbstractFile() = default; //virtual ensures dynamic binding (to ImageFile or TextFile); client should go to right file typ
	//friend AbstractFileVisitor;
};


