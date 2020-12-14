#pragma once
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <set>
// declaration of SimpleFileSystem class goes here

//TODO: check if correct
//class CatCommand;

class SimpleFileSystem : public AbstractFileSystem {
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> open_files;
public:
	virtual int addFile(std::string name, AbstractFile* file) override;
	virtual int deleteFile(std::string name) override;
	virtual AbstractFile* openFile(std::string name) override;
	virtual int closeFile(AbstractFile* file) override;
	//TODO: is friendship the way to go? Done in derived class because not all file systems need friendship?
	//friend CatCommand;
};