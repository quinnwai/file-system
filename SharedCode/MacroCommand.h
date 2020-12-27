#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>

class MacroCommand : public AbstractCommand { //TODO: make sure that this is right...
private:
	AbstractFileSystem* afs;
	std::vector<AbstractCommand*> vecCmds;
	AbstractParsingStrategy* aps;
public:
	MacroCommand(AbstractFileSystem*);
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
	void addCommand(AbstractCommand*); //TODO: make sure void works for both of these
	void setParseStrategy(AbstractParsingStrategy*);
};
