/*SimpleFileSystem.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration of the SimpleFileSystem class, inherits from AbstractFileSystem
*/

#pragma once
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <set>


class SimpleFileSystem : public AbstractFileSystem {
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> open_files;
public:
	virtual int addFile(std::string name, AbstractFile* file) override;
	virtual int deleteFile(std::string name) override;
	virtual AbstractFile* openFile(std::string name) override;
	virtual int closeFile(AbstractFile* file) override;
	virtual std::set<std::string> getFileNames() override;
};