/*LSCommand.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class declaration inheriting from AbstractCommand. Enables a user to display files in the system.
*/

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
