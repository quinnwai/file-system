/*CatCommand.cpp
Author: Quinn Wai Wong, Will LeVan
Email: qwong@wustl.edu, levanw@wustl.edu
Purpose: Concrete class implementation of a command that enables a user to add files to the system.
*/

#pragma once
#include "TouchCommand.h"
#include <string>
#include <iostream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs1, AbstractFileFactory* aff1) : afs(afs1), aff(aff1) {}

int TouchCommand::execute(string str) {
	AbstractFile* af = aff->createFile(str);
	if (af) {
		int addResult = afs->addFile(str, af);
		if (addResult != success) {
			delete af;
			cout << "could not add file" << endl;
			return addResult;
		}
		return success;
	}
	cout << "could not create file" << endl;
	return cannot_create_file;
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command : touch <filename>" << endl;
}