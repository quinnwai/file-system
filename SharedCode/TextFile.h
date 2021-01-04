/*TextFile.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration of the TextFile type class, inherits from AbstractFile
*/

#pragma once
#include<vector>
#include<string>
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
	TextFile(std::string str);
	virtual std::vector<char> read() override;
	virtual int write(std::vector<char> vec) override;
	virtual int append(std::vector<char> vec) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	friend class AbstractFileVisitor;
	virtual void accept(AbstractFileVisitor* afv) override;
	virtual AbstractFile* clone(std::string) override;
private:
	std::vector<char> contents;
	std::string fileName;
};