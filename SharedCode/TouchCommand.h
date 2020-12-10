#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand : public AbstractCommand {
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
};