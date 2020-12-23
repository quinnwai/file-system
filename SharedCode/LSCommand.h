#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class LSCommand : public AbstractCommand {
public:
	LSCommand(AbstractFileSystem*);
	virtual void displayInfo() override;
	virtual int execute(std::string) override;
private: 
	AbstractFileSystem* afs;
};
