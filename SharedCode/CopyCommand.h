/*CopyCommand.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration inheriting from AbstractCommand. Enables a user to copy/duplicate files in the system with a new name.
*/

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;
public:
	CopyCommand(AbstractFileSystem*);
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
};
