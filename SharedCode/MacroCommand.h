#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>

class MacroCommand : public AbstractCommand { 
private:
	AbstractFileSystem* afs;
	std::vector<AbstractCommand*> vecCmds;
	AbstractParsingStrategy* aps;
public:
	MacroCommand(AbstractFileSystem*);
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
};
