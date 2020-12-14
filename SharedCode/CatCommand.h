/*CatCommand.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration inheriting from AbstractCommand. Enables a user to append contents to a file
*/

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractFileVisitor.h"

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
	AbstractFileVisitor* afv;
public:
	CatCommand(AbstractFileSystem*, AbstractFileFactory*, AbstractFileVisitor*);
	virtual int execute(std::string str) override;
	virtual void displayInfo() override;
};
