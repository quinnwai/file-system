#pragma once
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <set>
// declaration of SimpleFileSystem class goes here


class SimpleFileSystem : public AbstractFileSystem {
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> open_files;
public:
	virtual int addFile(std::string name, AbstractFile* file) override;
	virtual int deleteFile(std::string name) override;
	virtual AbstractFile* openFile(std::string name) override;
	virtual int closeFile(AbstractFile* file) override;
	// virtual std::set<std::string> getFileNames() override; // this needs to be done
};