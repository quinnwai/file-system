/*RemoveCommand.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration inheriting from AbstractCommand. Enables a user to remove files from the system.
*/

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;
public:
	RemoveCommand(AbstractFileSystem*);
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
};
