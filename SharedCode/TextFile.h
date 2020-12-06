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
	virtual void accept(AbstractFileVisitor* afv) override;
	friend void visit_textFile(TextFile* t);
	//FWL:	not sure if these destructors (also one in ImageFile) needed b/c member vars are from std library but should be fine as is
	~TextFile() = default; //TODO: ask if these needed
private:
	std::vector<char> contents;
	std::string fileName;
};