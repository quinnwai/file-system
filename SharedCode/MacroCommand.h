#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include <vector>

class MacroCommand : public AbstractCommand { //TODO: make sure that this is right...
private:
	std::vector<AbstractCommand*> vecCmds;
	AbstractParsingStrategy* aps;
public:
	//TODO: see if default constructor needed like in touch
	//MacroCommand();
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
	void addCommand(AbstractCommand*); //TODO: make sure void works for both of these
	void setParseStrategy(AbstractParsingStrategy*);
};
