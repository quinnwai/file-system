#pragma once
#include<vector>
#include<string>
//#include "AbstractFileVisitor.h"
//#include "BasicDisplayVisitor.h"
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

//FWL: changed enums b/c of repeating ones
enum returnVals { success, invalid_pixel, size_mismatch, no_append, no_file_exists, file_already_open, file_already_exists, invalid_file, unopened_file, incorrect_password, quit_program, no_command_exists, command_already_exists, cannot_create_file};

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


