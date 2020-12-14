/*Touchommand.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration inheriting from AbstractCommand. Enables a user to add files to the system.
*/

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