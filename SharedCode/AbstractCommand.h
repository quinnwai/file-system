/*AbstractCommand.h
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Declaration of interface for commands in the program.
*/

#pragma once
#include <string>

class AbstractCommand {
public:
	virtual int execute(std::string str) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};