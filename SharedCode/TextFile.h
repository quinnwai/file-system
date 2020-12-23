#pragma once
#include<vector>
#include<string>
#include "AbstractFile.h"
// TextFile declaration goes here

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