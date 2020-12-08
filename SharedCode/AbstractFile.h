#pragma once
#include<vector>
#include<string>
//#include "AbstractFileVisitor.h"
//#include "BasicDisplayVisitor.h"
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

enum returns { success, invalid_pixel, size_mismatch, no_append, no_file_exists, already_open, already_exists, invalid_file, unopened_file, incorrect_password };

class AbstractFileVisitor;

class AbstractFile {
public:
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char> vec) = 0;
	virtual int append(std::vector<char> vec) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual ~AbstractFile() = default; //virtual ensures dynamic binding (to ImageFile or TextFile); client should go to right file typ
	//friend AbstractFileVisitor;
};


