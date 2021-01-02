/*MacroCommand.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Declaration of the MacroCommand class, inherits from AbstractCommand
*/

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
