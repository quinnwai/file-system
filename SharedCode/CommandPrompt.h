#pragma once
#include <string>
#include <map>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CommandPrompt {
	std::map<std::string, AbstractCommand*> map;
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	std::string prompt();
};
