/*AbstractFile.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Declaration of interface for file types in the program.
*/

#pragma once
#include "Enums.h"
#include<vector>
#include<string>

class AbstractFileVisitor;

class AbstractFile {
public:
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char> vec) = 0;
	virtual int append(std::vector<char> vec) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual void accept(AbstractFileVisitor*) = 0; //calls on correct visitor pattern method for concrete file type
	virtual AbstractFile* clone(std::string) = 0;
	virtual ~AbstractFile() = default; //virtual ensures dynamic binding (to ImageFile or TextFile); client should go to right file typ
};


