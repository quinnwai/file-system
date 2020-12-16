#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
	AbstractFileSystem* afs;
public:
	DisplayCommand(AbstractFileSystem*);
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
};

