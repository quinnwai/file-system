/*ImageFile.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration of the image file type, inherits from AbstractFile
*/

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
	virtual std::vector<char> read() override;
	friend class AbstractFileVisitor;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(std::string) override;
};
