#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class RemoveCommand : public AbstractCommand {
	//FWL: check this and make sure everything you need is in here for copy I just did bare bones
private:
	AbstractFileSystem* afs;
public:
	RemoveCommand(AbstractFileSystem*);
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
};
