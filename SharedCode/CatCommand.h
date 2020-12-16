/*CatCommand.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration inheriting from AbstractCommand. Enables a user to append contents to a file
*/

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;
public:
	CatCommand(AbstractFileSystem*);
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
};
