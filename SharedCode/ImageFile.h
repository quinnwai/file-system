#pragma once

#include "AbstractFile.h"
#include <string>
#include <vector>

// Image file class declaration here

class ImageFile : public AbstractFile {
	std::string name;
	std::vector<char> contents;
	char image_size;
public:
	ImageFile(std::string title);
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual int write(std::vector<char> info) override;
	virtual int append(std::vector<char> info) override;
	virtual void read() override;
	//FWL:	not sure if these destructors (also one in TextFile) needed b/c member vars are from std library but should be fine as is
	~ImageFile() = default; //TODO: ask if these needed
};
